# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

long long int a, b, c, d, e, f;
long long int ans[10005];

long long int fn(int n) {
    if(ans[n] != -1){
        return ans[n];
    }
    if( n == 0 ){
        ans[n] = a % 10000007;
        return ans[n];
    }
    if( n == 1 ){
        ans[n] = b % 10000007;
        return ans[n];
    }
    if( n == 2 ){
        ans[n] = c % 10000007;
        return ans[n];
    }
    if( n == 3 ){
        ans[n] = d % 10000007;
        return ans[n];
    }
    if( n == 4 ){
        ans[n] = e % 10000007;
        return ans[n];
    }
    if( n == 5 ){
        ans[n] = f % 10000007;
        return ans[n];
    }
    ans[n] = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ) % 10000007;
    return ans[n];
}

int main(){

    int t, n;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        memset(ans, -1, sizeof(ans));
        scanf("%lld %lld %lld %lld %lld %lld %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %lld\n", i, fn(n));
    }
    return 0;
}

