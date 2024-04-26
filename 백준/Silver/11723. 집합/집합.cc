#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int m;
int mask;

void input(){
    fastio
    cin >> m;
}

void solve(){
    string cmd;
    int num;
    while (m --){
        cin >> cmd;
        if (cmd == "add") {
            cin >> num;
            mask = mask | (1 << (num - 1));
        }
        else if (cmd == "remove"){
            cin >> num;
            mask = mask & (~ (1 << (num - 1)));
        }
        else if (cmd == "check"){
            cin >> num;
            cout << (bool) (mask & (1 << (num - 1))) << '\n';
        }
        else if (cmd == "toggle"){
            cin >> num;
            if (mask & (1 << (num - 1))) mask = mask & (~ (1 << (num - 1)));
            else mask = mask | (1 << (num - 1));
        }
        else if (cmd == "all") mask = ~ (1 << num);
        else mask = 0;         
    }
}

int main(){
    input();
    solve();
    return 0;
}