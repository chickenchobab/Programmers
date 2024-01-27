#include <iostream>
#include <algorithm>

using namespace std;

int c, n;
int price[22], people[22];
int dp[1111];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n;
    for (int i = 1; i <= n; i ++){
        cin >> price[i] >> people[i];
    }
    for (int i = 1; i <= c + 100; i ++){
        dp[i] = 111111;
    }
}

int main(){
    input();
    for (int i = 1; i <= n; i ++){
        for (int j = people[i]; j <= c + 100; j ++){
            dp[j] = min(dp[j], dp[j - people[i]] + price[i]);
        }
    }
    int ans = 111111;
    for (int i = 0; i <= 100; i ++){
        ans = min(ans, dp[c + i]);
    }
    cout << ans;
}