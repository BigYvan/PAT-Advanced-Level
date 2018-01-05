#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    double coeff[1001] = {0};
    int numberOfpoly= 0;int x = 0;
    double a = 0; double b = 0;
    int countMaxX = 0;
    cin >> numberOfpoly;
    while (numberOfpoly != 0) {
        cin >> x >> a;
        countMaxX = x > countMaxX ? x : countMaxX;
        coeff[x] = a;
        numberOfpoly--;
    }
    cin >> numberOfpoly;
    while (numberOfpoly != 0) {
        cin >> x >> b;
        countMaxX = x > countMaxX ? x : countMaxX;
        coeff[x] += b;
        numberOfpoly--;
    }
    for (int i = 0; i <= countMaxX; i++) {
        if (coeff[i] != 0) {
            numberOfpoly ++;
        }
    }
    cout << numberOfpoly;
    for (int i = countMaxX; i >= 0 ; i--) {
        if (coeff[i] != 0) {
            printf(" %d %.1f", i, coeff[i]);//用cout输出必须控制格式，保留一位小数
        }
    }
    return 0;
}
