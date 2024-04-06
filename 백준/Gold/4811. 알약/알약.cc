#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pill 30
using namespace std;

typedef long long ll;
int n;
ll dp[pill + 1][pill + 1] = {0,};

void input(){
    fastio
}

void make_table(){
    for (int w = 1; w <= pill; w ++){
        dp[w][0] = 1;
        for (int h = 1; h <= w; h ++){
            dp[w][h] = dp[w - 1][h] + dp[w][h - 1];
        }
    }
}

void solve(){
    make_table();
    while (1){
        cin >> n;
        if (n == 0) break;
        cout << dp[n][n] << '\n';
    }
}

int main(){
    input();
    solve();
    return 0;
}