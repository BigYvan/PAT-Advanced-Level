
#include <iostream>
#include <math.h>
using namespace std;

int JugePrime(int n){
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}


int main(int argc, const char * argv[]) {
    int N, D;
    while (1) {
        cin >> N;
        if (N < 0) {
            return 0;
        }else
            cin >> D;
        int len = 0, arr[100];
        int result = N;
        do{
            arr[len++] = result % D;
            result = result / D;
        }while (result!= 0);
        for (int i = 0; i < len; i++) {
            result = result * D + arr[i];
        }
        int ReverPrime = JugePrime(N) && JugePrime(result);
        if (ReverPrime) {
            printf("Yes\n");
        }else
            printf("No\n");
    }
    return 0;
}
//题目永远看不清系列，简单题目复杂化
//英语还是差啊
