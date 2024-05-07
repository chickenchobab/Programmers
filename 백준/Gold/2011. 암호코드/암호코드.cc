#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DIV 1000000
using namespace std;

string num;
int n;
long long dp[5005];

void input(){
    fastio
    cin >> num;
    n = num.size();
}

bool solve(){
    if (num[0] == '0') return false;

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i ++){
        if (num[(i - 1)] == '0'){
            if (num[(i - 1) - 1] != '1' && num[(i - 1) - 1] != '2') return false;
            dp[i] = dp[i - 2];
        }
        else if (num[(i - 1) - 1] == '1' || (num[(i - 1) - 1] == '2' && num[(i - 1)] <= '6'))
            dp[i] = (dp[i - 1] + dp[i - 2]) % DIV;  
        else    
            dp[i] = dp[i - 1];
    }

    return true;
}

int main(){
    input();
    if (solve()) cout << dp[n] % DIV;
    else cout << 0;
    return 0;
}