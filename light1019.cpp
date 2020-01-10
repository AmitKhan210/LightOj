# include <bits/stdc++.h>
using namespace std;

# define pp pair <int, int>
const int INF = INT_MAX;

class Prioritize{
public:
    bool operator () (const pp& p1, const pp& p2){
        return p1.second < p2.second;
    }
};

int main(){
    int tc, N, M, u, v, w;
    scanf("%d", &tc);
    for(int i = 1; i <= tc; i++){
        scanf("%d %d", &N, &M);
        vector <pp> G[N+1];
        for(int j = 0; j < M; j++){
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back(pp(v, w));
            G[v].push_back(pp(u, w));
        }
        int dis[N+1];
        for(int j = 1; j < N+1; j++){
            dis[j] = INF;
        }
        dis[1] = 0;
        priority_queue <pp, vector<pp>, Prioritize> q;
        q.push(pp(1, dis[1]));
        while(!q.empty()){
            u = q.top().first;
            q.pop();
            int Size = G[u].size();
            for(int j = 0; j < Size; j++){
                v = G[u][j].first;
                w = G[u][j].second;
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    q.push(pp(v, dis[v]));
                }
            }
        }
        if(dis[N] == INF){
            printf("Case %d: Impossible\n", i);
        }
        else{
            printf("Case %d: %d\n", i, dis[N]);
        }
    }
}
