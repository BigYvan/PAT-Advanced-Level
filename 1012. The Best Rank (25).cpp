//
//  main.cpp
//  1012
//
//  Created by Bigyvan on 2018/1/13.
//  Copyright © 2018年 Bigyvan. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct student{
    string Id;
    int C;
    int M;
    int E;
    int A;
}CsStudent[2000], GrageRank[2000];

string CheckStudent[2000];
int CRank[2000];
int MRank[2000];
int ERank[2000];
int ARank[2000];

int cmp( const int &a, const int &b ){
    if( a > b )
        return 1;
    else
        return 0;
}

int main(int argc, const char * argv[]) {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> CsStudent[i].Id >> CsStudent[i].C >> CsStudent[i].M >> CsStudent[i].E;
        CsStudent[i].A = (CsStudent[i].C + CsStudent[i].M + CsStudent[i].E) / 3;
    }
    
    for (int i = 0; i < M; i++) {
        cin >> CheckStudent[i];
    }
    
    for (int i = 0; i < N; i++) {
        CRank[i] = CsStudent[i].C;
        MRank[i] = CsStudent[i].M;
        ERank[i] = CsStudent[i].E;
        ARank[i] = CsStudent[i].A;
    }
    sort(CRank, CRank + N, cmp);
    sort(MRank, MRank + N, cmp);
    sort(ERank, ERank + N, cmp);
    sort(ARank, ARank + N, cmp);
    
    for (int i = 0; i < N; i++) {
        GrageRank[i].Id = CsStudent[i].Id;
        for (int j = N - 1; j >= 0; j--) {
            if (CsStudent[i].C == CRank[j]) {
                GrageRank[i].C = j + 1;
            }
            if (CsStudent[i].M == MRank[j]) {
                GrageRank[i].M = j + 1;
            }
            if (CsStudent[i].E == ERank[j]) {
                GrageRank[i].E = j + 1;
            }
            if (CsStudent[i].A == ARank[j]) {
                GrageRank[i].A = j + 1;
            }
        }
    }
    
    for (int i = 0; i < M; i++) {
        int flag = 1;
        for (int j = 0; j < N; j++) {
            if (CheckStudent[i] == GrageRank[j].Id) {
                flag = 0;
                for (int k = 1; k <= N; k++) {
                    if (GrageRank[j].A == k) {
                        cout << k << " A" << endl;
                        break;
                    }
                    if (GrageRank[j].C == k) {
                        cout << k << " C" << endl;
                        break;
                    }
                    if (GrageRank[j].M == k) {
                        cout << k << " M" << endl;
                        break;
                    }
                    if (GrageRank[j].E == k) {
                        cout << k << " E" << endl;
                        break;
                    }
                }
            }
        }
        if (flag == 1) {
            cout << "N/A" << endl;
        }
    }
    return 0;
}

//更有解，来自网络，比我自己写的差一半T_T，菜🐔！！

#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
    int id, best;
    int score[4], rank[4];
}stu[2005];
int exist[1000000], flag = -1;
bool cmp1(node a, node b) {return a.score[flag] > b.score[flag];}
int main() {
    int n, m, id;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;
    }
    for(flag = 0; flag <= 3; flag++) {
        sort(stu, stu + n, cmp1);
        stu[0].rank[flag] = 1;
        for(int i = 1; i < n; i++) {
            stu[i].rank[flag] = i + 1;
            if(stu[i].score[flag] == stu[i-1].score[flag])
                stu[i].rank[flag] = stu[i-1].rank[flag];
        }
    }
    for(int i = 0; i < n; i++) {
        exist[stu[i].id] = i + 1;
        stu[i].best = 0;
        int minn = stu[i].rank[0];
        for(int j = 1; j <= 3; j++) {
            if(stu[i].rank[j] < minn) {
                minn = stu[i].rank[j];
                stu[i].best = j;
            }
        }
    }
    char c[5] = {'A', 'C', 'M', 'E'};
    for(int i = 0; i < m; i++) {
        scanf("%d", &id);
        int temp = exist[id];
        if(temp) {
            int best = stu[temp-1].best;
            printf("%d %c\n", stu[temp-1].rank[best], c[best]);
        } else {
            printf("N/A\n");
        }
    }
    return 0;
}
