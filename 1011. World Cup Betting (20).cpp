#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    double game[9];
    int plan[3];
    for (int i = 0; i < 9; i++) {
        cin >> game[i];
    }
    for (int i = 0; i < 3; i++) {
        int max = game[i * 3] > game[i * 3 + 1] ? i * 3 : i * 3 + 1;
        max = game[max] > game[i * 3 + 2] ? max : i * 3 + 2;
        plan[i] = max;
    }
    char planChara[3] = {'W', 'T', 'L'};
    for (int i = 0; i < 3; i++) {
        printf("%c ", planChara[plan[i] % 3]);
    }
    double profit = (game[plan[0]] * game[plan[1]] * game[plan[2]] * 0.65 - 1 ) * 2;
    printf("%.2lf", profit);
    return 0;
}
