#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int ArrTime;
    int ProcTime;
};

bool cmp(node a, node b){
    return a.ArrTime < b.ArrTime;
}

int main(int argc, const char * argv[]) {
    int N, K;
    double waitTime = 0.0;
    int LateNumber = 0;
    cin >> N >> K;
    vector<node>person (N);
    for (int i = 0; i < N; i++) {
        int h, m, s;
        scanf("%d:%d:%d %d",&h, &m, &s, &person[i].ProcTime);
        if (person[i].ProcTime > 60) {
            person[i].ProcTime = 60;
        }
        person[i].ArrTime =  h * 3600 + m * 60 + s;
        if (person[i].ArrTime > 17*3600) {
            LateNumber++;
        }
    }
    sort(person.begin(), person.end(), cmp);
    vector<int>window (K, 28800);
//    for (int i = 0; i < K; i++) {
//        window[i] = 8 * 3600 + person[i].ProcTime * 60;
//        if (person[i].ArrTime < 8 * 3600) {
//            waitTime += 8 * 3600 - person[i].ArrTime;
//        }
//    }
// 可以服务的人少于k
    for (int i = 0; i < (N - LateNumber); i++) {
        auto it = min_element(window.begin(), window.end());
        if (person[i].ArrTime < * it) {
            waitTime += *it - person[i].ArrTime;
            *it += person[i].ProcTime * 60;
        }else
            *it = person[i].ArrTime + person[i].ProcTime * 60;
    }
    if (N - LateNumber == 0) {
        cout << "0.0" << endl;
        return 0;
    }
    double average = waitTime / 60.0 / (N - LateNumber);
    printf("%.1f\n", average);
    return 0;
}
