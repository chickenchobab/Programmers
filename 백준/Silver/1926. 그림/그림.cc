#include <iostream>
#include <algorithm>

using namespace std;

int n, m, cnt, area, ans;
int map[501][501], visited[501][501];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }
}

void dfs(int i, int j){
    visited[i][j] = 1;
    for (int d = 0; d < 4; d ++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
        if (visited[ni][nj]) continue;
        if (!map[ni][nj]) continue;
        area ++;
        dfs(ni, nj);
    }
}

int main(){

    input();

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (visited[i][j]) continue;
            if (!map[i][j]) continue;
            cnt ++;
            area = 1;
            dfs(i, j);
            ans = max(ans, area);
        }
    }

    cout << cnt << '\n' << ans;

    return 0;
}