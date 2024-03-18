#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;

void input(){
    fastio
    cin >> n;
}

void solve(){
    int ans = 0, cur;
    stack<int> st;
    for (int i = 1; i <= n; i ++){
        cin >> cur;
        int pop_cnt = 0;
        while (st.size() && st.top() > cur){
            ans = max(ans, (pop_cnt + 1) * st.top());
            st.pop();
            pop_cnt ++;
        }
        while (pop_cnt --) st.push(cur);
        st.push(cur);
    }

    int pop_cnt = 0;
    while (st.size()) {
        ans = max(ans, (pop_cnt + 1) * st.top());
        st.pop();
        pop_cnt ++;
    }

    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}