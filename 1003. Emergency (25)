
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int N, M, S, E;
    int Road[500][500];
    int teamsCount[500] = {0};//队伍数目和
    int num[500] = {0};//最短路径条数
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            Road[i][j] = 99999999;
            Road[j][i] = 99999999;
        }
    }//初始化
    int teams[500] = {0};//每个城市的救援队伍
    cin >> N >> M >> S >> E;
    for (int i = 0; i < N; i++) {
        cin >> teams[i];
    }
    for (int i = 0; i < M; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        Road[x][y] = Road[y][x] = z;
    }
    vector<int> dist(500,99999999);
    vector<bool> InOrNot(500,false);
    dist[S] = 0;
    teamsCount[S] = teams[S];
    num[S] = 1;
    for (int i = 0; i < N; i++) {
        int mindist = 99999999;
        int temp = -1;
        for (int j = 0; j < N; j++) {
            if ((!InOrNot[j]) && dist[j] < mindist) {
                temp = j;
                mindist = dist[j];
            }
        }
        if (temp == -1) {
            break;
        }
        InOrNot[temp] = true;
        for (int j = 0; j < N; j++) {
            if ((!InOrNot[j]) && Road[temp][j] != 99999999) {
                if (dist[temp] + Road[temp][j] < dist[j]) {
                    dist[j] = dist[temp] + Road[temp][j];
                    num[j] = num[temp];
                    teamsCount[j] = teamsCount[temp] + teams[j];
                }else if (dist[temp] + Road[temp][j] == dist[j]){
                    num[j] = num[j] + num[temp];
                    if (teamsCount[j] < teamsCount[temp] + teams[j]) {
                        teamsCount[j] = teamsCount[temp] + teams[j];
                    }
                }
            }
        }
    }
    printf("%d %d", num[E], teamsCount[E]);
    return 0;
}
