#include <iostream>

using namespace std;

int n, m, k;
int map[101][101], visited[101][101];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
int cnt, ans;

void input(){
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    int r, c;
    for (int i = 0; i < k; i ++){
        cin >> r >> c;
        map[r][c] = 1;
    }
}

void dfs(int i, int j){
    visited[i][j] = ++ cnt;
    for (int d = 0; d < 4; d ++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
        if (visited[ni][nj] || map[ni][nj] == 0) continue;
        dfs(ni, nj);
    }
}

int main(){
    input();
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (visited[i][j] || map[i][j] == 0) continue;
            cnt = 0;
            dfs(i, j);
            ans = max(ans, cnt);
        }
    }
    cout << ans;
}