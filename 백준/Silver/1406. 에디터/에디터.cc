#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string str;
int m, cur, len;
stack<char> l, r;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
    cin >> str >> m;
    cur = len = str.length();
    for (int i = 0; i < str.length(); i ++){
        l.push(str[i]);
    }
}

void print(){
    while(l.size()){
        r.push(l.top());
        l.pop();
    }
    while(r.size()){
        cout << r.top();
        r.pop();
    }
}

int main(){
    input();
    while (m --){
        char ch;
        cin >> ch;
        if (ch == 'P') {
            cin >> ch;
            l.push(ch);
        }
        else if (ch == 'B') {
            if (l.size()) 
                l.pop();    
        }
        else if (ch == 'L') {
            if (l.size()){
                r.push(l.top());
                l.pop();
            } 
        }
        else if (ch == 'D') {
            if (r.size()){
                l.push(r.top());
                r.pop();
            }
        }
    }
    print();
}