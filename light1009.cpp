# include <iostream>
# include <cstdio>
# include <vector>
# include <cstring>
# include <queue>
using namespace std;

# define Size 20005

int main(){

    int t, n, u, v, ans, vampire, lykan;
    scanf("%d", &t);
    int color[Size];
    vector <int> adj[Size];
    vector <int> node;
    for(int i = 1; i <= t; i++){
        ans = 0;
        vampire = 0;
        lykan = 0;
        scanf("%d", &n);
        for(int k = 1; k < Size; k++){
            adj[k].clear();
        }
        memset(color, 0, sizeof(color));
        node.clear();
        while(n--){
            scanf("%d %d", &u, &v);
            node.push_back(u);
            node.push_back(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int totalnode = node.size();
        for(int k = 0; k < totalnode; k++){
            int source = node[k];
            vampire = 0;
            lykan = 0;
            if(color[source] == 0){
                color[source] = 1;
                vampire++;
                queue <int> q;
                q.push(source);
                while(!q.empty()){
                    int top = q.front();
                    q.pop();
                    int len = adj[top].size();
                    for(int j = 0; j < len; j++){
                        if(color[adj[top][j]] == 0){
                            if(color[top] == 1){
                                color[adj[top][j]] = 2;
                                lykan++;
                            }
                            else if(color[top] == 2){
                                color[adj[top][j]] = 1;
                                vampire++;
                            }
                            q.push(adj[top][j]);
                        }
                    }
                }
            }
            if(vampire > lykan){
                ans += vampire;
            }
            else{
                ans += lykan;
            }
        }
        printf("Case %d: %d\n", i, ans);
    }


}
