# include <iostream>
# include <cstdio>
using namespace std;

int main(){

    int T, P, L, flang;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        flang = 1;
        scanf("%d %d", &P, &L);
        printf("Case %d:", i);
        int k = P - L;
        for(int j = L + 1; j <= k; j++){
            if(k % j == 0){ printf(" %d", j); flang = 0; }
        }
        if(flang) printf(" impossible\n");
        else printf("\n");

    }

}
