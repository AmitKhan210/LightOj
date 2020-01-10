# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

# define mx 100005

int arr[mx];
int lazy[4*mx];
int I, J, ans;

void build(int node, int l, int r){
    if(l == r){
        lazy[node] = 0;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    lazy[node] = lazy[left] + lazy[right];
}

void update(int node, int l, int r){
    if(l > J || r < I){
        return;
    }
    if(I <= l && r <= J){
        lazy[node]++;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    if(lazy[node] % 2 == 1){
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
        lazy[node] = 0;
    }
    update(left, l, mid);
    update(right, mid + 1, r);
}

void que(int node, int l, int r){
    if(l > I || r < I){
        return;
    }
    if(l == r){
        if(lazy[node] % 2 == 0){
            ans = arr[I];
        }
        else{
            if(arr[I] == 0){
                ans = 1;
            }
            else{
                ans = 0;
            }
        }
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    if(lazy[node] % 2 == 1){
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
        lazy[node] = 0;
    }
    que(left, l, mid);
    que(right, mid + 1, r);

}

int main(){

    int t, q, len;
    char c;
    char str[mx];
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        printf("Case %d:\n", i);
        scanf(" %s", str);
        len = strlen(str);
        for(int j = 0; j < len; j++){
            if(str[j] == '0'){
                arr[j+1] = 0;
            }
            else{
                arr[j+1] = 1;
            }
        }
        build(1, 1, len);
        scanf("%d", &q);
        while(q--){
            scanf(" %c", &c);
            if(c == 'I'){
                scanf("%d %d", &I, &J);
                update(1, 1, len);
            }
            else{
                scanf("%d", &I);
                que(1, 1, len);
                printf("%d\n", ans);
            }
        }

    }

}
