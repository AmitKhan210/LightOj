# include <iostream>
# include <cstdio>
# include <math.h>
using namespace std;

long long int Last(long long n, long long k){
    long long int x, y;
    if(k == 1){
        return n % 1000;
    }
    if(k % 2 == 0){
        x = Last(n, k / 2);
        x *= x;
        return x % 1000;
    }
    else{
        x = Last(n, k / 2);
        x *= x;
        x %= 1000;
        y = n % 1000;
        return (x * y) % 1000;
    }
}

long long int First(long long int n, long long int k){
    long double x = log10(n);
    if(floor(x) == ceil(x)){
        return 100;
    }
    long long int i, ans;
    x *= k;
    i = x;
    x -= i;
    ans = pow(10, x) * 1000;
    while(ans > 999){
        ans /= 10;
    }
    return ans;
}

int main(){
    int t;
    long long int n, k;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%lld %lld", &n, &k);
        printf("Case %d: %lld %03lld\n", i, First(n, k), Last(n,k));
    }
}
