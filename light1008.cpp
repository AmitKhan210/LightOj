# include <iostream>
# include <cstdio>
# include <math.h>
using namespace std;

int main(){

    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        long long int s;
        scanf("%lld", &s);
        double root = sqrt(s);
        long long int c = ceil(root);
        long long int f = floor(root);
        if(c == f){
            int r = root;
            if(r % 2 == 0){
                printf("Case %d: %d 1\n", i, r);
                continue;
            }
            else{
                printf("Case %d: 1 %d\n", i, r);
                continue;
            }
        }
        long long int mid = f * f + f + 1;
        if(mid == s){
            printf("Case %d: %lld %lld\n", i, c, c);
            continue;
        }
        else{
            if(f % 2 == 0){
                if(mid < s){
                    printf("Case %d: %lld %lld\n", i, c - (s - mid), c);
                    continue;
                }
                else{
                    printf("Case %d: %lld %lld\n", i, c, c - (mid - s));
                    continue;
                }
            }
            else{
                if(mid < s){
                    printf("Case %d: %lld %lld\n", i, c, c - (s - mid));
                    continue;
                }
                else{
                    printf("Case %d: %lld %lld\n", i, c - (mid - s), c);
                    continue;
                }
            }
        }

    }

}
