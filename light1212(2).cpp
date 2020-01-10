# include <bits/stdc++.h>
using namespace std;

int main(){

    int t, n, m, x, len;
    string command;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        printf("Case %d:\n", i);
        deque <int> d;
        len = 0;
        scanf("%d %d", &n, &m);
        while(m--){
            cin >> command;
            if(command == "pushLeft" || command == "pushRight"){
                scanf("%d", &x);
                if(len < n){
                    len++;
                    if(command == "pushLeft"){
                        d.push_front(x);
                        printf("Pushed in left: %d\n", x);
                    }
                    else{
                        d.push_back(x);
                        printf("Pushed in right: %d\n", x);
                    }
                }
                else{
                    printf("The queue is full\n");
                }
            }
            else{
                if(len != 0){
                    len--;
                    if(command == "popLeft"){
                        printf("Popped from left: %d\n", d.front());
                        d.pop_front();
                    }
                    else{
                        printf("Popped from right: %d\n", d.back());
                        d.pop_back();
                    }
                }
                else{
                    printf("The queue is empty\n");
                }
            }
        }
    }


    return 0;
}
