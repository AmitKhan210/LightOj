# include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
    bool operator < (const edge& p) const {
        return w < p.w;
    }
};

int parent[10005];
vector <edge> e;

int Find(int r){
    if(parent[r] == r){
        return parent[r];
    }
    else{
        parent[r] = Find(parent[r]);
        return parent[r];
    }
}

int mst(int n){
    sort(e.begin(), e.end());
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    int count = 0, sum = 0;
    int length = e.size();
    for(int i = 0; i < length; i++){
        int U = Find(e[i].u);
        int V = Find(e[i].v);
        if(U != V){
            parent[U] = V;
            count++;
            sum += e[i].w;
        }
        if(count == n - 1){
            break;
        }
    }
    return sum;
}


int main(){

    int t, n, m, a, ans, numOfairport;
    edge E;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        e.clear();
        numOfairport = 0;
        scanf("%d %d %d", &n, &m, &a);
        for(int j = 0; j < m; j++){
            scanf("%d %d %d", &E.u, &E.v, &E.w);
            if(E.w < a){
                e.push_back(E);
            }
        }
        ans = mst(n);
        for(int j = 1; j <= n; j++){
            if(parent[j] == j){
                numOfairport++;
            }
        }
        ans += numOfairport * a;
        printf("Case %d: %d %d\n", i, ans, numOfairport);
    }

}
