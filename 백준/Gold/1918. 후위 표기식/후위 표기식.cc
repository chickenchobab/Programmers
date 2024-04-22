#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

stack<char> st;
string pro, ans;

void input(){
    fastio
    cin >> pro;
}

int get_lev(char op){
    if (op == ')') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '(') return 3;
}

void solve(){
    char ch;
    int len = pro.length();

    for(int i = 0; i < len; i ++){
        ch = pro[i];

        if (isalpha(ch)) ans += ch;
        else if (ch == ')'){
            while (st.size() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (st.size() && get_lev(st.top()) >= get_lev(ch)){
            while (st.size() && get_lev(st.top()) >= get_lev(ch)){
                if (st.top() == '(') break;
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
        else{
            st.push(ch);
        }
    }

    while (st.size()){
        ans += st.top();
        st.pop();
    }

    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}