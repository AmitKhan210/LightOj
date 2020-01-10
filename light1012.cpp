# include <iostream>
# include <cstdio>
# include <utility>
# include <queue>
# include <cstring>
using namespace std;
# define pii pair <int, int>
int fx[4] = {1, -1, 0, 0};
int fy[4] = {0, 0, 1, -1};

int main(){

    int t, x, y, w, h, ans;
    char place[25][25];
    int vis[25][25];
    char c;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        ans = 1;
        scanf("%d %d", &w, &h);
        memset(vis, 0, sizeof(vis));
        for(int j = 1; j <= h; j++){
            for(int k = 1; k <= w; k++){
                scanf(" %c", &c);
                place[k][j] = c;
                if(place[k][j] == '@'){
                    x = k;
                    y = j;
                }
            }
        }
        queue <pii> q;
        q.push(pii(x, y));
        vis[x][y] = 1;
        while(!q.empty()){
            pii top = q.front();
            q.pop();
            for(int m = 0; m < 4; m++){
                x = top.first + fx[m];
                y = top.second + fy[m];
                if(x >= 1 && x <= w && y >= 1 && y <= h && vis[x][y] == 0 && place[x][y] != '#'){
                    vis[x][y] = 1;
                    q.push(pii(x,y));
                    ans++;
                }
            }
        }

        printf("Case %d: %d\n", i, ans);

    }
}
