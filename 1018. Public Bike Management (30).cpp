
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int weight[510];
int inf = 99999999;
int matrix[510][510];

vector<int>pre[510];
vector<int>temppath, path;
int minNeed = inf;
int minBack = inf;
int visit[510], dis[510];

void dfs1(int v) {
    temppath.push_back(v);
    if(v == 0) {
        int need = 0, back = 0;
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            if(weight[id] > 0) {
                back += weight[id];
            } else {
                if(back > (0 - weight[id])) {
                    back += weight[id];
                } else {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++)
        dfs1(pre[v][i]);
    temppath.pop_back();
}

int main(int argc, const char * argv[]) {
    int C, N, S, M;
    cin >> C >> N >> S >> M;
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        weight[i] = n - C / 2;
    }
    fill(matrix[0], matrix[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    for (int i = 0; i < M; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        matrix[a][b] = d;
        matrix[b][a] = d;
    }
    //dijkstra
    dis[0] = 0;
    for (int i = 0; i <= N; i++) {
        int MIN = inf;
        int k = -1;
        for (int j = 0; j <=  N; j++) {
            if (visit[j] == 0 && dis[j] < MIN) {
                MIN = dis[j];
                k = j;
            }
        }
        if (k == -1) {
            break;
        }
        visit[k] = 1;
        //松弛
        for (int j = 0;j <= N ; j++) {
            if (visit[j] == 0 && matrix[k][j] != inf) {
                if (dis[k] + matrix[k][j] < dis[j]) {
                    dis[j] = dis[k] + matrix[k][j];
                    pre[j].clear();
                    pre[j].push_back(k);
                }else if (dis[j] == dis[k] + matrix[k][j]){
                    pre[j].push_back(k);
                }
            }
        }
    }
    dfs1(S);
    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
    return 0;
}
