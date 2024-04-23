#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string str;
stack<int> st;

void input(){
    fastio
    cin >> str;
}

int solve(){
    int ans = 0;
    int len = str.length();

    for (int i = 0; i < len; i ++){
        
        char ch = str[i];
        int mul, add = 0;
        
        if (ch == ')'){
            while (st.size() && st.top() != -2){
                if (st.top() == -3) return 0;
                add += st.top();
                st.pop();
            }
            if (st.empty()) return 0;
            st.pop();
            st.push(2 * max(add, 1));
        }
        else if (ch == ']'){
            while (st.size() && st.top() != -3){
                if (st.top() == -2) return 0;
                add += st.top();
                st.pop();
            }
            if (st.empty()) return 0;
            st.pop();
            st.push(3 * max(add, 1));
        }
        else {
            if (ch == '(') st.push(-2);
            else if (ch == '[') st.push(-3);
            else return 0;
        }
    }
    
    while (st.size()){
        if (st.top() == -2 || st.top() == -3) return 0;
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main(){
    input();
    cout << solve();
    return 0;
}