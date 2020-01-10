# include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        printf("Case %d:\n", i);
        stack <string> Front, Back;
        string current, command, url;
        current = "http://www.lightoj.com/";
        while(true){
            cin >> command;
            if(command == "QUIT"){
                break;
            }
            else if(command == "VISIT"){
                cin >> url;
                Back.push(current);
                current = url;
                while(!Front.empty()){
                    Front.pop();
                }
            }
            else if(command == "BACK"){
                if(Back.empty()){
                    cout << "Ignored" << endl;
                    continue;
                }
                Front.push(current);
                current = Back.top();
                Back.pop();
            }
            else if(command == "FORWARD"){
                if(Front.empty()){
                    cout << "Ignored" << endl;
                    continue;
                }
                Back.push(current);
                current = Front.top();
                Front.pop();
            }
            cout << current << endl;
        }
    }

}
