#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int t[1500002], p[1500002], dp[1500002];

void input(){
    fastio
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        cin >> t[i] >> p[i];
    }
}

void solve(){
    int ans = 0;
    for (int i = 1; i <= n + 1; ++ i){
        dp[i] = max(dp[i], dp[i - 1]);
        if (i + t[i] > n + 1) continue;
        dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
    }
    for (int i = 1; i <= n + 1; ++ i){
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}