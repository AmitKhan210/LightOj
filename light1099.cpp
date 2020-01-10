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

    int t, n, r, u, v, w, lastRoad;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d %d", &n, &r);
        vector <pp> G[n+1];
        for(int j = 0; j < r; j++){
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back(pp(v, w));
            G[v].push_back(pp(u, w));
        }
        int dis[n+1];
        int second_dis[n+1];
        for(int j = 1; j <= n; j++){
            dis[j] = INF;
        }
        dis[1] = 0;
        priority_queue <pp, vector <pp>, Prioritize> q;
        q.push(pp(1, dis[1]));
        while(!q.empty()){
            u = q.top().first;
            q.pop();
            int Size = G[u].size();
            for(int j = 0; j < Size; j++){
                v = G[u][j].first;
                w = G[u][j].second;
                if(dis[v] > dis[u] + w){
                    second_dis[v] = dis[v];
                    dis[v] = dis[u] + w;
                //cout << v << "  v..dis.. " << dis[v] << endl;
                    q.push(pp(v, dis[v]));
                    if(v == n){
                        lastRoad = w;
                    }
                }
                else if(dis[v] == dis[u] + w){
                    if(v == n && lastRoad > w){
                        lastRoad = w;
                    }
                }
                else if(second_dis[v] > dis[u] + w){
                    second_dis[v] = dis[u] + w;
                }
            }
        }
        if(second_dis[n] > dis[n] + 2 * lastRoad){
            printf("Case %d: %d\n", i, dis[n] + 2 * lastRoad);
        }
        else{
            printf("Case %d: %d\n", i, second_dis[n]);
        }
    }
}
