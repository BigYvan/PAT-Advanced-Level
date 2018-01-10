#include <iostream>

double a[1001] = {0.0};
double final[2001] = {0.0};

int main(int argc, const char * argv[]) {
    int N, M;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        double y;
        scanf("%d %lf", &x, &y);
        a[x] = y;
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x;
        double y;
        scanf("%d %lf", &x, &y);
        for (int j = 0; j < 1001; j++) {
            final[x + j] += y * a[j];
        }
    }
    int count = 0;
    for (int i = 2000; i >= 0; i--) {
        if (final[i] != 0.0) {
            count ++;
        }
    }
    printf("%d", count);
    for (int i = 2000; i >= 0; i--) {
        if (final[i] != 0.0) {
            printf(" %d %.1lf", i, final[i]);
        }
    }
    return 0;
}
