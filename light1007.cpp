# include <bits/stdc++.h>
using namespace std;


int seive(){
    int i, val, total = 0, j;
    val = sqrt(SIZE) + 1;
    for(i = 2; i <= SIZE; i++) flag[i] = 1;

    for(i = 2; i < val; i++){
        if(flag[i]){
            for(j = i; j * i <= SIZE; j++){
                flag[j*i] = 0;
            }
        }
    }
    for(i = 2; i <= SIZE; i++){
        if(flag[i]) prime[total++] = i;
    }
    return total;
}

