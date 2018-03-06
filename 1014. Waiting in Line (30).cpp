#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int ProcessingTime[1010];
int DoneTime[1010];
int HeadQue[20];
int QueueTime[20];

void TimeConv(int time){
    if (DoneTime[time] - ProcessingTime[time] >= 540) {
        cout << "Sorry" << endl;
    }else
        printf("%02d:%02d\n", DoneTime[time] / 60 + 8, DoneTime[time] % 60);
}

int main(int argc, const char * argv[]) {
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    for (int i = 0; i < K; i++) {
        cin >> ProcessingTime[i];
    }
    vector<queue<int>>window;
    window.resize(20);
    for (int i = 0; i < N * M; i++) {
        QueueTime[i % N] += ProcessingTime[i];
        DoneTime[i] = QueueTime[i % N];
        window[i%N].push(ProcessingTime[i]);
    }
    for (int i = 0; i < N; i++) {
        HeadQue[i] = window[i].front();
    }
    for (int i = N * M; i < K; i++) {
        int WindowNum = (int)(min_element(HeadQue, HeadQue + N) - HeadQue);
        QueueTime[WindowNum] += ProcessingTime[i];
        DoneTime[i] = QueueTime[WindowNum];
//        for (int j = 0; j < N; j++) {
//            if (j != WindowNum) {
//                HeadQue[j] = HeadQue[j] - HeadQue[WindowNum];
//            }
//        }
        window[WindowNum].pop();
        window[WindowNum].push(ProcessingTime[i]);
        HeadQue[WindowNum] += window[WindowNum].front();
    }
    for (int i = 0; i < Q; i++) {
        int num = 0;
        cin >> num;
        TimeConv(num - 1);
    }
    return 0;
}
//一直三个点没过，差点崩溃，度娘救我
//对于那些无法在17:00点之前被处理的客户输出sorry,
//这句话不要理解成一定要在17:00之前完成业务的处理,
//比如, 某个客户在16:54的是开始处理他的业务,
//在17:37分的时候结束业务处理, 那么对于这个客户,
//还是应该输出17:37而不是sorry.
