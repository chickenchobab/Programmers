#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define div 1000000000
using namespace std;

typedef long long ll;
int n;
ll dp[100][10][1 << 10];

void input(){
    fastio
    cin >> n;
}

ll solve(){
    ll sum = 0;

    for (int j = 1; j <= 9; j ++) {
        dp[0][j][1 << j] = 1;
    }

    for (int i = 1; i < n; i ++){
        for (int j = 0; j <= 9; j ++){
            for (int k = 1; k <= (1 << 10) - 1; k ++){
                if (j != 0) dp[i][j][k | (1 << j)] += (dp[i - 1][j - 1][k] % div);
                if (j != 9) dp[i][j][k | (1 << j)] += (dp[i - 1][j + 1][k] % div);
            }
        }
    }

    for (int j = 0; j <= 9; j ++){
        sum += (dp[n - 1][j][(1 << 10) - 1] % div);
    }

    return sum % div;
}

int main(){
    input();
    cout << solve();
    return 0;
}