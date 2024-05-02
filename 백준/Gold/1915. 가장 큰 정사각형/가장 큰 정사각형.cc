#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int map[1001][1001];

void input(){
    fastio
    cin >> n >> m;
    string str;
    for (int i = 1; i <= n; i ++){
        cin >> str;
        for (int j = 1; j <= m; j ++){
            map[i][j] = str[j - 1] - '0';
        }
    }
}

void solve(){

    int ans = 0;

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (map[i][j] == 0) {
                // cout << "000" << ' ';
                continue;
            }
            map[i][j] = min(map[i - 1][j - 1], min(map[i][j - 1], map[i - 1][j])) + 1;
            ans = max(ans, map[i][j]);
        }
        // cout << '\n';
    }
    
    cout << ans * ans;
}

int main(){
    input();
    solve();
    return 0;
}