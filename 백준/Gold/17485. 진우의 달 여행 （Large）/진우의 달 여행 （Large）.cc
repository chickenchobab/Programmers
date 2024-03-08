#include <iostream>
#include <algorithm>
#define MAX 10000001
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int map[1001][1001];

int dp[1001][1001][3];

void input(){
    fastio
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> map[i][j];
            for (int d = 0; d < 3; d ++){
                dp[i][j][d] = MAX;
            }
        }
    }
}

void solve(){

    int ans = 100000001;

    for (int j = 1; j <= m; j ++){
        for (int d = 0; d < 3; d ++){
            dp[1][j][d] = map[1][j];
        }
    }

    for (int i = 2; i <= n; i ++){
        for (int j = 1; j <= m; j ++) {
            if (j < m) dp[i][j][0] = min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + map[i][j];
            if (j > 1) dp[i][j][2] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][0]) + map[i][j];
            dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + map[i][j];
        }
    }

    for (int j = 1; j <= m; j ++){
        for (int d = 0; d < 3; d ++){
            ans = min(ans, dp[n][j][d]);
        }
    }
    
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}