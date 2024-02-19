#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;
int divisor = 1000000000;
int dp[100][10][1 << 10];

void input(){
    fastio
    cin >> n;
}

int solve(){
    int sum = 0;

    for (int j = 1; j <= 9; j ++) {
        dp[0][j][1 << j] = 1;
    }

    for (int i = 1; i < n; i ++){
        for (int j = 0; j <= 9; j ++){
            for (int k = 1; k <= (1 << 10) - 1; k ++){
                if (j != 0) dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % divisor;
                if (j != 9) dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % divisor;
            }
        }
    }

    for (int j = 0; j <= 9; j ++){
        sum = (sum + dp[n - 1][j][(1 << 10) - 1]) % divisor;
    }

    return sum % divisor;
}

int main(){
    input();
    cout << solve();
    return 0;
}