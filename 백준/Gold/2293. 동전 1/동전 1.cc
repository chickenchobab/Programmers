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
}

int main(){

    input(); 

    sort(coin + 1, coin + n + 1);

    dp[0] = 1;
    for (int i = 1; i <= n; i ++){
        for (int j = coin[i]; j <= k; j ++){
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }

    // for (int i = 1; i <= k; i ++) cout << dp[i] << ' ';
    cout << dp[k];

}