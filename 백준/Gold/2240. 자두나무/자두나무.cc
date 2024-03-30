#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TIME 1000
#define TREE 2
#define MOVE 30
using namespace std;

int t, w;
bool a[1001], b[1001];

int dp[TIME + 1][TREE][MOVE + 1];

void input(){
    fastio
    cin >> t >> w;
    int num;
    for (int i = 1; i <= t; i ++){
        cin >> num;
        if (num == 1) a[i] = 1;
        else b[i] = 1;
    }
}

void solve(){
    int ans = 0;

    dp[1][0][0] = a[1];
    dp[1][1][1] = b[1];

    for (int i = 2; i <= t; i ++){
        dp[i][0][0] = dp[i - 1][0][0] + a[i];
        for (int j = 1; j <= i && j <= w; j ++){
            dp[i][0][j] = max(dp[i - 1][0][j], dp[i - 1][1][j - 1]) + a[i];
            dp[i][1][j] = max(dp[i - 1][1][j], dp[i - 1][0][j - 1]) + b[i];
        }
    }
    for (int i = 0; i <= w; i ++){
        ans = max(ans, dp[t][0][i]);
        ans = max(ans, dp[t][1][i]);
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}