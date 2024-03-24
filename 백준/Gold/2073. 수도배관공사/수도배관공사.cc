#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int d, p;
int l[351], c[351];

int dp[100001];

void input(){
    fastio
    cin >> d >> p;

    for (int i = 1; i <= p; i ++) {
        cin >> l[i] >> c[i];
    }
}

void solve(){
    
    for (int i = 1; i <= p; i ++){
        dp[l[i]] = max(dp[l[i]], c[i]);
        for (int j = d; j >= l[i]; j --){
            if (dp[j - l[i]]) dp[j] = max(dp[j], min(dp[j - l[i]], c[i]));
        }
    }

    cout << dp[d];
}

int main(){
    input();
    solve();
    return 0;
}