# include <bits/stdc++.h>
using namespace std;

int main(){

    int t, z;
    double R, r, angel, pi = 3.14159,  x, n;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%lf %lf", &R, &n);
        angel = pi / n;
        x = sin(angel);
        r = R * x;
        r /= (x + 1);
        if(ceil(r) == floor(r)){
            printf("Case %d: %.0lf\n", i, r);
        }
        else{
            printf("Case %d: %.7lf\n", i, r);
        }
    }

    return 0;
}
