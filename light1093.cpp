# include <iostream>
# include <cstdio>
using namespace std;

# define mx 100005

int arr[mx];
int tree[4*mx][2];
int I, J, ans, ansmin, ansmax;

void build(int node, int l, int r){
    if(l == r){
        tree[node][0] = arr[l];
        tree[node][1] = arr[l];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    if(tree[left][0] < tree[right][0]){
        tree[node][0] = tree[left][0];
    }
    else{
        tree[node][0] = tree[right][0];
    }
    if(tree[left][1] > tree[right][1]){
        tree[node][1] = tree[left][1];
    }
    else{
        tree[node][1] = tree[right][1];
    }
}

void que(int node, int l, int r){
    if(l > J || r < I){
        return;
    }
    if(I <= l && r <= J){
        if(tree[node][0] < ansmin){
            ansmin = tree[node][0];
        }
        if(tree[node][1] > ansmax){
            ansmax = tree[node][1];
        }
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    que(left, l, mid);
    que(right, mid + 1, r);
}

int main(){

    int t, n, d;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d %d", &n, &d);
        for(int j = 1; j <= n; j++){
            scanf("%d", &arr[j]);
        }
        build(1, 1, n);
        ans = 0;
        I = 1;
        J = d;
        while(J <= n){
            ansmin = 100000000;
            ansmax = 0;
            que(1, 1, n);
            if(ans < ansmax - ansmin){
                ans = ansmax - ansmin;
            }
            I++;
            J++;
        }
        printf("Case %d: %d\n", i, ans);
    }
}
