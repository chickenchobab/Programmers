#include <iostream>
#include <algorithm>

using namespace std;

int n, m, cnt, ans;
int map[301][301], visited[301][301], water[301][301];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void reset(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (map[i][j]) map[i][j] = max(0, map[i][j] - water[i][j]);
            visited[i][j] = water[i][j] = 0;
        }
    }
}

void dfs(int i, int j){
    visited[i][j] = 1;
    int ice = 0;
    for (int d=0; d<4; d++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
        if (visited[ni][nj]) continue;
        if (map[ni][nj] == 0){
            water[i][j] ++;
            continue;
        }
        dfs(ni, nj);
    }
}

int main(){

    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> map[i][j];
            visited[i][j] = water[i][j] = 0;
        }
    }

    while (cnt < 2){
        cnt = 0;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (!map[i][j]) continue;
                if (visited[i][j]) continue;
                dfs(i, j);
                cnt ++;
            }
        }
        if (cnt == 0) {
            ans = cnt;
            break;
        }
        if (cnt < 2) ans ++;
        reset();
    }
    
    cout << ans;

}