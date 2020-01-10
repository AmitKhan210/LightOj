# include <bits/stdc++.h>
using namespace std;

int n, m;
int c[1005];

bool f(int ans){
    int v = 0, con = 1, sum = 0;
    while(con <= m && v < n){
        sum += c[v];
        v++;
        if(sum > ans){
            con++;
            sum = 0;
            v--;
        }
    }
    if(v == n){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int T, mid;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d %d", &n, &m);
        for(int j = 0; j < n; j++){
            scanf("%d", &c[j]);
        }
        int low = 0, high = 1000000000;
        while(low <= high){
            mid = (high + low) / 2;
            if(mid == low){
                if(f(mid)){
                    break;
                }
                else{
                    mid = high;
                    break;
                }
            }
            if(f(mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        printf("Case %d: %d\n", i, mid);
    }

}
