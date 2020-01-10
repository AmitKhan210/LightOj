# include <iostream>
# include <cstdio>
using namespace std;

# define mx 100005

struct nod{
    int z;
    int o;
    int t;
};

nod tree[4*mx];
int lazy[4*mx];
int A, B, s, save;

void build(int node, int l, int r){
    if(l == r){
        tree[node].z = 1;
        tree[node].o = 0;
        tree[node].t = 0;
        lazy[node] = 0;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid+1, r);
    tree[node].z = tree[left].z + tree[right].z;
    tree[node].o = tree[left].o + tree[right].o;
    tree[node].t = tree[left].t + tree[right].t;
    lazy[node] = 0;
}

void update(int node, int l, int r){
    if(r < A || B < l){
        return;
    }
    if(A <= l && r <= B){
        lazy[node]++;
        save = tree[node].o;
        tree[node].o = tree[node].z;
        tree[node].z = tree[node].t;
        tree[node].t = save;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    if(lazy[node] % 3 == 1){
        save = tree[left].o;
        tree[left].o = tree[left].z;
        tree[left].z = tree[left].t;
        tree[left].t = save;
        save = tree[right].o;
        tree[right].o = tree[right].z;
        tree[right].z = tree[right].t;
        tree[right].t = save;
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
        lazy[node] = 0;
    }
    else if(lazy[node] % 3 == 2){
        save = tree[left].o;
        tree[left].o = tree[left].t;
        tree[left].t = tree[left].z;
        tree[left].z = save;
        save = tree[right].o;
        tree[right].o = tree[right].t;
        tree[right].t = tree[right].z;
        tree[right].z = save;
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
        lazy[node] = 0;
    }
    update(left, l, mid);
    update(right, mid+1, r);
    tree[node].o = tree[left].o + tree[right].o;
    tree[node].t = tree[left].t + tree[right].t;
    tree[node].z = tree[left].z + tree[right].z;
}

void que(int node, int l, int r){
    if(r < A || B < l){
        return;
    }
    if(A <= l && r <= B){
        s += tree[node].z;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;
    if(lazy[node] % 3 == 1){
        save = tree[left].o;
        tree[left].o = tree[left].z;
        tree[left].z = tree[left].t;
        tree[left].t = save;
        save = tree[right].o;
        tree[right].o = tree[right].z;
        tree[right].z = tree[right].t;
        tree[right].t = save;
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
        lazy[node] = 0;
    }
    else if(lazy[node] % 3 == 2){
        save = tree[left].o;
        tree[left].o = tree[left].t;
        tree[left].t = tree[left].z;
        tree[left].z = save;
        save = tree[right].o;
        tree[right].o = tree[right].t;
        tree[right].t = tree[right].z;
        tree[right].z = save;
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
        lazy[node] = 0;
    }
    que(left, l, mid);
    que(right, mid+1, r);

}

int main(){
    int t, n, q, option;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        printf("Case %d:\n", i);
        scanf("%d %d", &n, &q);
        build(1, 1, n);
        while(q--){
            scanf("%d %d %d", &option, &A, &B);
            if(option == 0){
                A++;
                B++;
                update(1, 1, n);
            }
            else{
                s = 0;
                A++;
                B++;
                que(1, 1, n);
                printf("%d\n", s);
            }
        }
    }
}
