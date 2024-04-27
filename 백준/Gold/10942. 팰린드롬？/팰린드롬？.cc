#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int arr[2002];
bool dp[2002][2002];

void input(){
    fastio
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> arr[i];
    cin >> m;
}

void palindrome(){
    for (int i = 1; i <= n; i ++)
        dp[i][i] = 1;
    for (int i = 2; i <= n; i ++)
        if (arr[i] == arr[i - 1])
            dp[i - 1][i] = 1;

    for (int s = n - 2; s >= 1; s --){
        for (int e = s + 2; e <= n; e ++){
            if (arr[s] == arr[e] && dp[s + 1][e - 1])
                dp[s][e] = 1;
        }
    }
}

void solve(){
    int a, b;
    palindrome();
    while (m --){
        cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
}

int main(){
    input();
    solve();
    return 0;
}