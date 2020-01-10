# include <iostream>
# include <cstdio>
using namespace std;

int main(){

    long long  int n, m, ans;
    int t;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++){
        scanf("%lld %lld", &n, &m);
        ans = m * m;
        n /= 2*m;
        ans *= n;
        printf("Case %d: %lld\n", i, ans);
    }

    return 0;
}
