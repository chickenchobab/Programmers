#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DIV (1000000000+1+1+1+1+1+1+1)
using namespace std;

int t;
int n, l, r;
typedef long long ll;
ll dp[21][21][21];

void input(){
    fastio
    cin >> t;
}

void init(){
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= l; j ++){
            for (int k = 1; k <= r; k ++){
                dp[i][j][k] = -1;
            }
        }
    }
    dp[1][1][1] = 1;
}

ll solve(int num, int left, int right){
    ll sum = 0;

    if (left + right > num + 1 || left < 1 || right < 1 || num < 1) return 0;
    if (dp[num][left][right] != -1) return dp[num][left][right];

    sum = (solve(num - 1, left - 1, right) + solve(num - 1, left, right - 1) + solve(num - 1, left, right) * (num - 2));
    return dp[num][left][right] = sum;
}

int main(){
    input();
    while (t --){
        init();
        cout << solve(n, l, r) << '\n';
    }

    return 0;
}