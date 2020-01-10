# include <bits/stdc++.h>
using namespace std;
# define SIZE 1000

bool flag[SIZE+5];
int prime[SIZE+5];

int seive(){
    int i, val, total = 0, j;
    val = sqrt(SIZE) + 1;
    for(i = 2; i <= SIZE; i++) flag[i] = 1;

    for(i = 2; i < val; i++){
        if(flag[i]){
            for(j = i; j * i <= SIZE; j++){
                flag[j*i] = 0;
            }
        }
    }
    for(i = 2; i <= SIZE; i++){
        if(flag[i]) prime[total++] = i;
    }
    return total;
}

int main(){
    int total = seive();
    queue <int> q;
    vector <int> pf;
    int dis[SIZE * 5];
    int T, s, t;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d %d", &s, &t);
        memset(dis, 0, sizeof(dis));
        if(s == t){
            printf("Case %d: 0\n", i);
            continue;
        }
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            pf.clear();
            for(int j = 0; prime[j] < u && j < total; j++){
                if(u % prime[j] == 0){
                    pf.push_back(prime[j]);
                }
            }
            int v, len = pf.size();
            for(int j = 0; j < len; j++){
                v = u + pf[j];
                if(dis[v] == 0 && v <= t){
                    q.push(v);
                    dis[v] = dis[u] + 1;
                }
            }
        }
        if(dis[t] == 0){
            printf("Case %d: -1\n", i);
        }
        else{
            printf("Case %d: %d\n", i, dis[t]);
        }
    }
    return 0;
}
