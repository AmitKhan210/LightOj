# include <bits/stdc++.h>
using namespace std;

int main(){

    int t, myPos, liftPos, ans;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++){
        scanf("%d %d", &myPos, &liftPos);
        ans = 19;
        ans += (4 * abs(myPos - liftPos));
        ans += (4 * abs(myPos - 0));
        printf("Case %d: %d\n", i, ans);
    }

    return 0;
}
