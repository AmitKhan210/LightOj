# include <bits/stdc++.h>
using namespace std;
# define pp pair <int, int>
const int INF = INT_MAX;

class Prioritize{
public:
    bool operator() ( const pp& p1, const pp& p2){
        return p1.second < p2.second;
    }
};

int main(){

    int T, n, m, u, v, w, t;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d %d", &n, &m);
        vector <pp> G[n];
        for(int j = 0; j < m; j++){
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back(pp(v, w));
            G[v].push_back(pp(u, w));
        }
        scanf("%d", &t);
        int cost[n];
        for(int j = 0; j < n; j++){
            cost[j] = INF;
        }
        cost[t] = 0;
        priority_queue <pp, vector <pp> , Prioritize> q;
        q.push(pp(t, cost[t]));
        while(!q.empty()){
            u = q.top().first;
            q.pop();
            int Size = G[u].size();
            for(int j = 0; j < Size; j++){
                v = G[u][j].first;
                w = G[u][j].second;
                if(cost[v] > cost[u] && cost[v] > w){
                    if(cost[u] > w){
                        cost[v] = cost[u];
                    }
                    else{
                        cost[v] = w;
                    }
                    q.push(pp(v, cost[v]));
                }
            }

        }
        printf("Case %d:\n", i);
        for(int j = 0; j < n; j++){
            if(cost[j] == INF){
                printf("Impossible\n");
            }
            else{
                printf("%d\n", cost[j]);
            }
        }
    }

}
