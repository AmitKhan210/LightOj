# include <bits/stdc++.h>
using namespace std;

struct edge{
    string u, v;
    int w;
    bool operator < (const edge& p) const {
        return w < p.w;
    }
};

map <string, string> parent;
vector <edge> e;
vector <string> n;

string Find(string r){
    if(parent[r] == r){
        return r;
    }
    parent[r] = Find(parent[r]);
    return parent[r];
}

int mst(){

    sort(e.begin(), e.end());
    int Size = n.size();
    for(int i = 0; i < Size; i++){
        parent[n[i]] = n[i];
    }
    int sum = 0;
    Size = e.size();
    for(int i = 0; i < Size; i++){
        string U = Find(e[i].u);
        string V = Find(e[i].v);
        if(U != V){
            parent[U] = V;
            sum += e[i].w;
        }
    }
    return sum;

}

int main(){

    int tc, m, cost, Size, ans;
    string city1, city2;
    set <string> representative;
    edge E;
    scanf("%d", &tc);
    for(int i = 1; i <= tc; i++){
        representative.clear();
        e.clear();
        n.clear();
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            cin >> city1 >> city2 >> cost;
            n.push_back(city1);
            n.push_back(city2);
            E.u = city1;
            E.v = city2;
            E.w = cost;
            e.push_back(E);
        }
        ans = mst();
        Size = n.size();
        for(int j = 0; j < Size; j++){
            if(parent[n[j]] == n[j]){
                representative.insert(n[j]);
            }
        }
        Size = representative.size();
        if(Size > 1){
            printf("Case %d: Impossible\n", i);
        }
        else{
            printf("Case %d: %d\n", i, ans);
        }
    }
}
