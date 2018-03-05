
#include <iostream>
#include <algorithm>
using namespace std;

int Matrix[1001][1001];
int CityWeConcern[1001];
bool CityVisited[1001];

void DFS(int city){
    CityVisited[city] = true;
    for (int j = 1; j < 1001; j++) {
        if (Matrix[city][j] != 0 && !CityVisited[j]) {
            DFS(j);
        }
    }
}

int main(int argc, const char * argv[]) {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M ; i++) {
        int x, y;
        cin >> x >> y;
        Matrix[x][y] = Matrix[y][x] = 1;
    }
    for (int i = 0; i < K; i++) {
        cin >> CityWeConcern[i];
    }
    for (int i = 0; i < K; i++) {
        fill(CityVisited, CityVisited+1001, false);
        int cnt = 0;
        CityVisited[CityWeConcern[i]] = true;
        for (int j = 1; j <= N; j++) {
            if (CityVisited[j] == false) {
                DFS(j);
                cnt++;
            }
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}
