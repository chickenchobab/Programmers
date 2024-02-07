#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int n;
int stride[101][101];
ll dp[101][101]; // 현재 칸까지의 경로의 수


void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> stride[i][j];
        }
    }
}

int main(){
    input();
    dp[1][1] = 1;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            if (i == n && j == n) break;

            if (i + stride[i][j] <= n)
                dp[i + stride[i][j]][j] += dp[i][j];
                    
            if (j + stride[i][j] <= n)
                dp[i][j + stride[i][j]] += dp[i][j];
                     
        }
    }
    cout << dp[n][n];
}