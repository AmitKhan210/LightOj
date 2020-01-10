# include <bits/stdc++.h>
using namespace std;

int main(){

    int t, n, d, ans;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        ans = 0;
        scanf("%d", &n);
        for(int j = 1; j <= n; j++){
            scanf("%d", &d);
            if(d > 0){
                ans += d;
            }
        }
        printf("Case %d: %d\n", i, ans);
    }
    return 0;

}
