#include <iostream>
#include <deque>
#include <string>

using namespace std;

string str, bomb;
deque<char> dq;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str >> bomb;
}

int main(){
    input();  
    int i, j, len = bomb.length();
    for (i = 0; i < str.size(); i ++) {
        dq.push_back(str[i]);
        if (dq.back() != bomb[len - 1]) continue;
        for (j = 0; j < len && j < dq.size(); j ++) 
            if (dq[dq.size() - 1 - j] != bomb[len - 1 - j]) break;
        if (j != len) continue;
        for (j = 0; j < len; j ++) 
            dq.pop_back();
    }

    if (dq.size())
        for (char tmp : dq) cout << tmp;
    else 
        cout << "FRULA";
    
    
    
}