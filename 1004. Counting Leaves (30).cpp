
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int>point[100];
int level[100] = {0};//每个节点的level属性
int levelOfLeaf[100] = {0};//每一层的叶子节点数
int maxLevel = 0;//最大层数

void bfs(){
    queue<int>q;
    q.push(1);
    level[1] = 1;
    while (!q.empty()) {
        int node;
        node = q.front();
        maxLevel = max(maxLevel, level[node]);
        q.pop();
        if (point[node].empty()) {
            levelOfLeaf[level[node]]++;
        }
        for (int i = 0; i < point[node].size(); i++) {
            level[point[node][i]] = level[node] + 1;
            q.push(point[node][i]);
        }
        
    }
}
int main(int argc, const char * argv[]) {
    int N, M;
    int a, b, c;
    scanf("%d%d",&N, &M);
    for (int i = 0;i < M ; i++) {
        scanf("%d%d", &a, &b);
        for (int j = 0; j < b; j++) {
            scanf("%d", &c);
            point[a].push_back(c);
        }
    }
    bfs();
    printf("%d", levelOfLeaf[1]);
    for (int i = 2; i <= maxLevel;i++ ) {
        printf(" %d", levelOfLeaf[i]);
    }
    return 0;
}
