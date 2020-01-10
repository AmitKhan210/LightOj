# include <iostream>
# include <cstdio>
# include <utility>
# include <cstring>
# include <queue>
# include <climits>
using namespace std;
# define pii pair<int, int>
char graph[15][15];
int cost[15][15];
int realcost[15][15];
int level[15][15];
int vis[15][15];
int Count[15][15];
int fx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int fy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
int m, n, knight;
queue <pii> q;


void bfs(pii source, int value){
    int x, y;
    memset(cost, 0, sizeof(cost));
    memset(vis, 0, sizeof(vis));
    level[source.first][source.second] = 0;
    vis[source.first][source.second] = 1;
    Count[source.first][source.second]++;
    cost[source.first][source.second] = 0;
    q.push(source);
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        for(int i = 0; i < 8; i++){
            x = top.second + fx[i];
            y = top.first + fy[i];
            if(x >= 1 && x <= n && y >= 1 && y <= m && vis[y][x] == 0){
                Count[y][x]++;
                vis[y][x] = 1;
                q.push(pii(y, x));
                level[y][x] = level[top.first][top.second] + 1;
                if(level[y][x] % value == 0){
                    cost[y][x] = level[y][x] / value;
                    realcost[y][x] += cost[y][x];
                }
                else{
                    cost[y][x] = (level[y][x] / value) + 1;
                    realcost[y][x] += cost[y][x];
                }
            }
        }
    }
}

int main(){

    int t, value, ans;
    bool possible;
    pii source;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        knight = 0;
        possible = false;
        ans = INT_MAX;
        memset(realcost, 0, sizeof(realcost));
        memset(Count, 0, sizeof(Count));
        scanf("%d %d", &m, &n);
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= n; k++){
                scanf(" %c", &graph[j][k]);
                if(graph[j][k] != '.'){
                    knight++;
                }
            }
        }
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= n; k++){
                if(graph[j][k] != '.'){
                    source.first = j;
                    source.second = k;
                    value = graph[j][k] - 48;
                    bfs(source, value);
                }
            }
        }
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= n; k++){
                if(Count[j][k] == knight){
                    possible = true;
                    if(ans > realcost[j][k]){
                        ans = realcost[j][k];
                    }
                }
            }

        }
        if(possible){
            printf("Case %d: %d\n", i, ans);
        }
        else{
            printf("Case %d: -1\n", i);
        }
    }

}
