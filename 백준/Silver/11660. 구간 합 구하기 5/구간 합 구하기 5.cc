#include <iostream>

using namespace std;

int n, m, x1, y1, x2, y2;
int dp[1025][1025];

void input(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i ++){
        dp[0][i] = dp[i][0] = 0;
    }

    int tmp;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> tmp;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            dp[i][j] += tmp;
        }
    }
}


int main(){

    input();
    for (int i = 1; i <= m; i ++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - (dp[x1 - 1][y2] + dp[x2][y1 - 1]) + dp[x1 - 1][y1 - 1] << '\n';
    }

}