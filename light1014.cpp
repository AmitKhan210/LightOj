

# include <iostream>
# include <cstdio>
# include <vector>
# include <math.h>
# include <algorithm>
using namespace std;


int main(){

    int t, len, len2;
    long long int P, L, sq;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        vector <long long int> v, v2;
        scanf("%lld %lld", &P, &L);
        P -= L;
        sq = sqrt(P);
        if(sq < L){
            for(long long int j = 1; j <= sq; j++){
                if(P % j == 0 && L < P / j){
                    v.push_back(P / j);
                }
            }
            len = v.size();
            printf("Case %d:", i);
            if(len == 0){
                printf(" impossible\n");
                continue;
            }
            for(int j = len - 1; j >= 0; j--){
                printf(" %lld", v[j]);
            }
            printf("\n");
        }
        else if(sq == L){
            for(long long int j = 1; j < sq; j++){
                if(P % j == 0){
                    v.push_back(P / j);
                }
            }
            len = v.size();
            printf("Case %d:", i);
            if(len == 0){
                printf(" impossible\n");
                continue;
            }
            for(int j = len - 1; j >= 0; j--){
                printf(" %lld", v[j]);
            }
            printf("\n");
        }
        else{
            for(long long int j = 1; j <= sq; j++){
                if(P % j == 0){
                    v2.push_back(P/j);
                    if(j > L && j != P/j){
                        v.push_back(j);
                    }
                }
            }
            len = v.size();
            len2 = v2.size();
            printf("Case %d:", i);
            if(len + len2 == 0){
                printf(" impossible\n");
                continue;
            }
            for(int j = 0; j < len; j++){
                printf(" %lld", v[j]);
            }
            for(int j = len2 - 1; j >= 0; j--){
                printf(" %lld", v2[j]);
            }
            printf("\n");
        }

    }

}
