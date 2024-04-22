#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

stack<char> st;
string str;

void input(){
    fastio
    cin >> str;
}

void solve(){
    char ch;
    int len = str.length();

    for(int i = 0; i < len; i ++){
        ch = str[i];

        if (isalpha(ch)) cout << ch;
        else if (ch == ')'){
            while (st.size() && st.top() != '('){
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else if (ch == '*' || ch == '/'){
            while (st.size() && st.top() != '(' && st.top() != '+' && st.top() != '-'){
                cout << st.top();
                st.pop();
            }
            st.push(ch);
        }
        else if (ch == '+' || ch == '-') {
            while (st.size() && st.top() != '('){
                cout << st.top();
                st.pop();
            }
            st.push(ch);
        }
        else{
            st.push(ch);
        }
    }

    while (st.size()){
        cout << st.top();
        st.pop();
    }
}

int main(){
    input();
    solve();
    return 0;
}