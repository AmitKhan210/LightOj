# include <iostream>
# include <cstdio>
using namespace std;

# define mx 100005
long long int tree[4*mx];
long long int prop[4*mx];
int p, q;
long long int v;

void build(int node, int b, int e){
    if(b == e){
        prop[node] = 0;
        tree[node] = 0;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
    prop[node] = prop[left] + prop[right];
}

void update(int node, int b, int e){
    if(q < b || e < p){
        return;
    }
    if(p <= b && e <= q){
        tree[node] += (e - b + 1) * v;
        prop[node] += v;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    if(prop[node] != 0){
        tree[left] += (mid - b + 1) * prop[node];
        tree[right] += (e - mid) * prop[node];
        prop[left] += prop[node];
        prop[right] += prop[node];
        prop[node] = 0;
    }
    update(left, b, mid);
    update(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}

long long int que(int node, int b, int e){
    if(e < p || q < b){
        return 0;
    }
    if(p <= b && e <= q){
        return tree[node];
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    if(prop[node] != 0){
        tree[left] += (mid - b + 1) * prop[node];
        tree[right] += (e - mid) * prop[node];
        prop[left] += prop[node];
        prop[right] += prop[node];
        prop[node] = 0;
    }
    long long int a1 = que(left, b, mid);
    long long int a2 = que(right, mid + 1, e);
    return a1 + a2;
}

int main(){

    int t, n, c;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d %d", &n, &c);
        build(1, 1, n);
        int option;
        printf("Case %d:\n", i);
        while(c--){
            scanf("%d", &option);
            if(option == 0){
                scanf("%d %d %lld", &p, &q, &v);
                p++;
                q++;
                update(1, 1, n);
            }
            else{
                scanf("%d %d", &p, &q);
                p++;
                q++;
                printf("%lld\n", que(1, 1, n));
            }
        }
    }

    return 0;
}
