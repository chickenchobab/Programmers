#include <iostream>
#include <algorithm>
#define MAX 10001
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int memory[101], cost[101];

int sum;
int dp[20000002];

void input(){
    fastio
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> memory[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> cost[i];
    }
}

void solve(){

    for (int i = 1; i <= 20000000; i ++) {
        dp[i] = MAX;
    }

    for (int i = 1; i <= n; i ++) {
        //dp[memory[i]] = min(dp[memory[i]], cost[i]);
        for (int j = m; j >= 0; j --) {
            dp[j + memory[i]] = min(dp[j + memory[i]], dp[j] + cost[i]);
        }
    }

    int ans = MAX;
    for (int i = m; i <= 20000000; i ++){
        ans = min(ans, dp[i]);
    }

    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}