#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct bill{
    string name;
    int TollTime, mouth, day, hour, min, status;
};

bool cmp(bill a, bill b){
    return a.name != b.name ? a.name < b.name : a.TollTime < b.TollTime;
}

double billFromZero(bill call, int *TollEachHour){
    double total = TollEachHour[call.hour] * call.min + TollEachHour[24] * 60 *call.day;
    for (int i = 0;  i < call.hour; i++) {
        total += TollEachHour[i] * 60;
    }
    return total / 100.0;
}

int main(int argc, const char * argv[]) {
    int TollEachHour[25];
    int N;
    TollEachHour[24] = 0;
    for (int i = 0; i < 24; i++) {
        cin >> TollEachHour[i];
        TollEachHour[24] += TollEachHour[i];
    }
    cin >> N;
    vector<bill>line(N);
    for (int i = 0; i < N; i++) {
        cin >> line[i].name;
        scanf("%d:%d:%d:%d", &line[i].mouth, &line[i].day, &line[i].hour, &line[i].min);
        string on_off;
        cin >> on_off;
        if (on_off == "on-line") {
            line[i].status = 1;
        }else
            line[i].status = 0;
        line[i].TollTime = line[i].day * 24 * 60 + line[i].hour * 60 + line[i].min;
    }
    sort(line.begin(), line.end(), cmp);
    map<string, vector<bill> > custom;
    for (int i = 1; i < N; i++) {
        if (line[i].name == line[i - 1].name && line[i - 1].status == 1 && line[i].status == 0) {
            custom[line[i - 1].name].push_back(line[i - 1]);
            custom[line[i].name].push_back(line[i]);
        }
    }
    for (auto it : custom) {
        vector<bill> temp = it.second;
        cout << it.first;
        printf(" %02d\n",temp[0].mouth);
        double total = 0.0;
        for (int i = 1; i < temp.size(); i += 2) {
            double t = billFromZero(temp[i], TollEachHour) - billFromZero(temp[i - 1], TollEachHour);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",temp[i - 1].day, temp[i - 1].hour, temp[i - 1].min
                   ,temp[i].day, temp[i].hour, temp[i].min, temp[i].TollTime - temp[i - 1].TollTime, t);
            total += t;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}
