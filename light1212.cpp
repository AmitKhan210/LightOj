# include <bits/stdc++.h>
using namespace std;

int main(){

    int t, n, m, x, llen, rlen;
    string command;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        printf("Case %d:\n", i);
        stack <int> sleft, sright;
        queue <int> qleft, qright;
        llen = 0;
        rlen = 0;
        scanf("%d %d", &n, &m);
        while(m--){
            cin >> command;
            if(command == "pushLeft" || command == "pushRight"){
                scanf("%d", &x);
                if(llen + rlen < n){
                    if(command == "pushLeft"){
                        llen++;
                        qleft.push(x);
                        sleft.push(x);
                        printf("Pushed in left: %d\n", x);
                    }
                    else if(command == "pushRight"){
                        rlen++;
                        qright.push(x);
                        sright.push(x);
                        printf("Pushed in right: %d\n", x);
                    }
                }
                else{
                    printf("The queue is full\n");
                }
            }
            else{
                if(llen + rlen != 0){
                    if(command == "popLeft"){
                        if(!sleft.empty() && llen != 0){
                            llen--;
                            printf("Popped from left: %d\n", sleft.top());
                            sleft.pop();
                        }
                        else{
                            rlen--;
                            printf("Popped from left: %d\n", qright.front());
                            qright.pop();

                        }
                    }
                    else if(command == "popRight"){
                        if(!sright.empty() && rlen != 0){
                            rlen--;
                            printf("Popped from right: %d\n", sright.top());
                            sright.pop();
                        }
                        else{
                            llen--;
                            printf("Popped from right: %d\n", qleft.front());
                            qleft.pop();

                        }
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
