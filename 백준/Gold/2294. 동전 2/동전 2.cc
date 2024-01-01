#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int coin[101], dp[10001];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> coin[i];
    }
    for (int i = 1; i <= k; i ++){
        dp[i] = 10001;
    }
}

int main(){

    input();
    sort(coin + 1, coin + n + 1);

    for (int i = 1; i <= n; i ++){
        for (int j = coin[i]; j <= k; j ++){
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    if (dp[k] == 10001) dp[k] = -1;
    cout << dp[k];
}