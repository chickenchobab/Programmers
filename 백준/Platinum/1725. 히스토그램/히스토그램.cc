#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;

int ans = 0;
stack<int> st;

void input(){
    fastio
    cin >> n;
}

void make_stair(int h){
    int pop_cnt = 0;
    while (st.size() && st.top() > h){
        ans = max(ans, (pop_cnt + 1) * st.top());
        st.pop();
        pop_cnt ++;
    }
    if (h == 0) return;
    while (pop_cnt --) st.push(h);
    st.push(h);
}

void solve(){
    int h;
    for (int i = 1; i <= n; i ++){
        cin >> h;
        make_stair(h);
    }
    make_stair(0);
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}