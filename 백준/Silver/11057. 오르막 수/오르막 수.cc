#include <iostream>
#define mod (10000 + 1 + 1 + 1 + 1 + 1 + 1 + 1)

using namespace std;

int n;
long long dp[10][1001];

int main(){
    cin >> n;

    for (int i = 0; i <= 9; i ++){
        dp[i][1] = 1;
    }

    for (int i = 2; i <= n; i ++){
        dp[0][i] = dp[0][i - 1];
        for (int j = 1; j <= 9; j ++){
            dp[j][i] = 0;
            for (int k = 0; k <= j; k ++){
                dp[j][i] = (dp[j][i] + dp[k][i - 1]) % mod;
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i <= 9; i ++){
        sum = (sum + dp[i][n]) % mod;
    }

    cout << sum;
}