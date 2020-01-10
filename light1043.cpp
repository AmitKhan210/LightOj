# include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        double ab, ac, bc, r, ad;
        scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &r);
        r = 1 / r;
        r++;
        ad = (ab * ab) / r;
        printf("Case %d: %.7lf\n", i, sqrt(ad));
    }
    return 0;
}
