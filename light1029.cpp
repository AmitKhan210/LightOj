# include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
    bool operator < (const edge& p) const {
        return w < p.w;
    }
};

int parent[105];
vector <edge> e;

int Find(int r){
    if(parent[r] == r){
        return r;
    }
    parent[r] = Find(parent[r]);
    return parent[r];
}

int mst(int n){

    sort(e.begin(), e.end());
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
    int sum = 0, count = 0;
    int Size = e.size();
    for(int i = 0; i < Size; i++){
        int U = Find(e[i].u);
        int V = Find(e[i].v);
        if(U != V){
            parent[U] = V;
            sum += e[i].w;
            count++;
        }
        if(count == n){
            break;
        }
    }
    return sum;

}

int inverse_mst(int n){

    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
    int sum = 0, count = 0;
    int Size = e.size();
    for(int i = Size - 1; i >= 0; i--){
        int U = Find(e[i].u);
        int V = Find(e[i].v);
        if(U != V){
            parent[U] = V;
            sum += e[i].w;
            count++;
        }
        if(count == n){
            break;
        }
    }
    return sum;
}

int main(){

    int t, n, best, worst, ans;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d", &n);
        e.clear();
        edge E;
        while(scanf("%d %d %d", &E.u, &E.v, &E.w) && (E.u || E.v || E.w)){
            e.push_back(E);
        }
        best = mst(n);
        worst = inverse_mst(n);
        ans = best + worst;
        if(ans % 2 == 0){
            printf("Case %d: %d\n", i, ans / 2);
        }
        else{
            printf("Case %d: %d/2\n", i, ans);
        }
    }
}
