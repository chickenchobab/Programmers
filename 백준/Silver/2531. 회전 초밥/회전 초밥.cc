#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, d, k, c;
int belt[30003];

int ans, res;
int cnt[3003];

void input(){
    fastio
    cin >> n >> d >> k >> c;  
}

void solve(){
    
    for (int s = 1; s < k; s ++){
        cin >> belt[s];
        if (cnt[belt[s]] ++ == 0) res ++;
    }
    for (int s = k; s <= n; s ++){
        cin >> belt[s];
        if (cnt[belt[s - k]] -- == 1) res --;
        if (cnt[belt[s]] ++ == 0) res ++;
        ans = max(ans, res + (cnt[c] == 0));
    }
    for (int s = n + 1; s <= n + k; s ++){
        if (cnt[belt[s - k]] -- == 1) res --;
        if (cnt[belt[s - n]] ++ == 0) res ++;
        ans = max(ans, res + (cnt[c] == 0));
    }

    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}