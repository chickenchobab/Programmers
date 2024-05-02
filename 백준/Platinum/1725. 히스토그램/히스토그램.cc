#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int ans;
stack<pair<int, int>> st;

void input(){
    fastio
    cin >> n;
}

void make_stair(int h){
    int cnt = 0;
    while (st.size() && st.top().first >= h){
        cnt += st.top().second;
        ans = max(ans, st.top().first * cnt);
        st.pop();
    }
    if (h) st.push({h, cnt + 1});
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