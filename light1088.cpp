# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;

int main(){

    int t, a, b, n, q, ans, num;
    vector <int> v;
    vector <int> :: iterator low, up;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d %d", &n, &q);
        printf("Case %d:\n", i);
        v.clear();
        for(int j = 0; j < n; j++){
            scanf("%d", &num);
            v.push_back(num);
        }
        while(q--){
            scanf("%d %d", &a, &b);
            low = lower_bound(v.begin(), v.end(), a);
            up = upper_bound(v.begin(), v.end(), b);
            ans = up - low;
            printf("%d\n", ans);
        }
    }
}
