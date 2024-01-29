#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[501][501], visited[501][501];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
typedef long long ll;
long long dp[501][501];

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> map[i][j];
        }
    }
}
 
void reset(){
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            visited[i][j] = 0;
        }
    }
}

int dfs(int i, int j){
    int sum = 0;
    if (dp[i][j]) return dp[i][j];
    for (int d = 0; d < 4; d ++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 1 || ni > n || nj < 1 || nj > n) continue;
        if (visited[ni][nj]) continue;
        if (map[ni][nj] <= map[i][j]) continue;
        visited[ni][nj] = 1;
        sum = max(sum, dfs(ni, nj));
        visited[ni][nj] = 0;
    }
    return (dp[i][j] = sum + 1);
}

int main(){
    input();
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            visited[i][j] = 1;
            ans = max(ans, dfs(i, j));
            visited[i][j] = 0;
        }
    }
    cout << ans;
}