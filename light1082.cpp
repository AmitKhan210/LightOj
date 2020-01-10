# include <iostream>
# include <cstdio>
# include <algorithm>
using namespace std;

int a[100005];
int tree[400020];
int I, J;
int MIN;

void build(int node, int l, int r){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    int left_node = node * 2;
    int right_node = node * 2 + 1;
    int mid = (l + r) / 2;
    build(left_node, l, mid);
    build(right_node, mid+1, r);
    if(tree[left_node] < tree[right_node]){
        tree[node] = tree[left_node];
    }
    else{
        tree[node] = tree[right_node];
    }
}

void que(int node, int l, int r){
    if(r < I || J < l){
        return;
    }
    if(I <= l && r <= J){
        if(MIN > tree[node]){
            MIN = tree[node];
        }
        return;
    }
    int left_node = node * 2;
    int right_node = node * 2 + 1;
    int mid = (l + r) / 2;
    que(left_node, l, mid);
    que(right_node, mid+1, r);
}

int main(){

    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        int N, q;
        scanf("%d %d", &N, &q);
        for(int j = 1; j <= N; j++){
            scanf("%d", &a[j]);
        }
        build(1, 1, N);
        printf("Case %d:\n", i);
        for(int j = 1; j <= q; j++){
            scanf("%d %d", &I, &J);
            MIN = 100005;
            que(1, 1, N);
            printf("%d\n", MIN);
        }
    }

}
