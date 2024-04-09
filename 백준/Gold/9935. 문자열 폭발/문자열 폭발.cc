#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string instr, outstr, bomb;

void input(){
    fastio
    cin >> instr >> bomb;
}

void solve(){
    int len = bomb.length();

    int i, j;
    for (i = 0; i < instr.length(); i ++){
        outstr.push_back(instr[i]);

        if (outstr.back() == bomb.back() && outstr.length() >= len){
            for (j = 0; j < len; j ++){
                if (outstr[outstr.length() - 1 - j] != bomb[len - 1 - j]) break;
            }
            if (j != len) continue;
            for (j = 0; j < len; j ++){
                outstr.pop_back();
            }
        }
    }

    if (outstr.length()) cout << outstr;
    else cout << "FRULA";
}

int main(){
    input();
    solve();
    return 0;
}