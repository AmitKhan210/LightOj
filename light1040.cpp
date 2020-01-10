# include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
    bool operator < (const edge& p) const{
        return w < p.w;
    }
};

int parent[55];
vector <edge> e;
int numOfedge;

int Find(int r){
    if(parent[r] == r){
        return r;
    }
    parent[r] = Find(parent[r]);
    return parent[r];
}

int mst(int n){
    numOfedge = 0;
    sort(e.begin(), e.end());
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    int sum = 0;
    int Size = e.size();
    for(int i = 0; i < Size; i++){
        int U = Find(e[i].u);
        int V = Find(e[i].v);
        if(U != V){
            parent[U] = V;
            sum += e[i].w;
            numOfedge++;
        }
        if(numOfedge == n - 1){
            break;
        }
    }
    return sum;
}

int main(){

    int t, n, ans, total, length;
    edge E;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        e.clear();
        ans = 0;
        total = 0;
        scanf("%d", &n);
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                scanf("%d", &length);
                if(j == k){
                    ans += length;
                    continue;
                }
                else if(length == 0){
                    continue;
                }
                E.u = j;
                E.v = k;
                E.w = length;
                e.push_back(E);
                total += length;
            }
        }
        total -= mst(n);
        ans += total;
        if(numOfedge != n - 1){
            printf("Case %d: -1\n", i);
        }
        else{
            printf("Case %d: %d\n", i, ans);
        }

    }

}
