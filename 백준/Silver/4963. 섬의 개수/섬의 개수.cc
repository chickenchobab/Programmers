#include <iostream>

using namespace std;

int w, h;
int map[51][51], visited[51][51];
int di[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dj[] = {0, 0, 1, -1, 1, -1, 1, -1};

void dfs(int i, int j){
    visited[i][j] = 1;
    for (int d=0; d<8; d++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni<1 || ni>h || nj<1 || nj>w) continue;
        if (visited[ni][nj]) continue;
        if (map[ni][nj] == 0) continue;
        dfs(ni, nj);
    }
}

int main(){

    while(1){
        int ans = 0;

        cin >> w >> h;
        if (!w && !h) break;

        for (int i=1; i<=h; i++){
            for (int j=1; j<=w; j++){
                cin >> map[i][j];
                visited[i][j] = 0;
            }
        }

        for (int i=1; i<=h; i++){
            for (int j=1; j<=w; j++){
                if (visited[i][j]) continue;
                if (map[i][j] == 0) continue;
                dfs(i, j);
                ans ++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}