#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
int n;
ll dp[99][22]; // cur num case proper to prv num

void input(){
    fastio
    cin >> n;
}

void solve(){
    int num;

    cin >> num;
    dp[0][num] = 1;
    
    for (int i = 1; i < n - 1; i ++){
        cin >> num;
        for (int j = 0; j <= 20; j ++){
            if (j - num >= 0) dp[i][j] += dp[i - 1][j - num];
            if (j + num <= 20) dp[i][j] += dp[i - 1][j + num];
        }
    }
    cin >> num;
    cout << dp[n - 2][num];
}

int main(){
    input();
    solve();
    return 0;
}