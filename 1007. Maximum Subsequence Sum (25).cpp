#include <iostream>

int main(int argc, const char * argv[]) {
    int K, S, E, Sum, maxSum, temp;
    int sequence[10001];
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &sequence[i]);
    }
    S = E = Sum= temp = 0;
    maxSum = -1;
    for (int i = 0; i < K; i++) {
        Sum = Sum + sequence[i];
        if (Sum < 0){
            Sum = 0;
            temp = i + 1;
        }else if(Sum > maxSum){
            maxSum = Sum;
            E = i;
            S = temp;
        }
    }
    if (maxSum < 0) {
        printf("0 %d %d", sequence[0], sequence[K-1]);
    }else
        printf("%d %d %d",maxSum, sequence[S], sequence[E]);
    return 0;
}
