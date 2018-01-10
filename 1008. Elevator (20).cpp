#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    int sum = 0;
    int numberPre = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int numberNext;
        scanf("%d", &numberNext);
        if (numberNext > numberPre) {
            sum = sum + (numberNext - numberPre) * 6;
        }else
            sum = sum + (numberPre - numberNext) * 4;
        numberPre = numberNext;
        sum += 5;
    }
    printf("%d", sum);
    return 0;
}
