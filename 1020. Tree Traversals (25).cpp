#include <iostream>
#include <vector>
using namespace std;

int PostOrder[30], InOrder[30];
vector<int>LevelOrder(10000,-1);


void PreOder(int root, int start, int end, int index_){
    if (start > end) {
        return;
    }
    int i = start;
    while (i < end && PostOrder[root] != InOrder[i]) {
        i++;
    }
    LevelOrder[index_] = PostOrder[root];
    PreOder(root - 1 - end + i, start, i - 1, 2 * index_ + 1);
    PreOder(root - 1, i + 1, end, 2 * index_ + 2);
    
}

int main(int argc, const char * argv[]) {
    int N;
    int control = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d",&PostOrder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &InOrder[i]);
    }
    PreOder(N - 1, 0, N - 1, 0);
    for (int i = 0; i < 10000; i++) {
        if (LevelOrder[i] != -1) {
            if (control != 0) {
                printf(" ");
            }
            printf("%d", LevelOrder[i]);
            control++;
        }
    }
    return 0;
}
