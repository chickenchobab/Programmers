#include <iostream>
#include <algorithm>

using namespace std;

int n, h, cnt, ans;
int map[101][101], visited[101][101];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void dfs(int i, int j){

    visited[i][j] = 1;
    for (int d=0; d<4; d++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni<1 || ni>n || nj<1 || nj>n) continue;
        if (visited[ni][nj]) continue;
        if (map[ni][nj] <= h) continue;
        dfs(ni, nj);
    }
}

int main(){

    cin >> n;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    for (h=0; h<=100; h++){

        cnt = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                visited[i][j] = 0;
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if (map[i][j] <= h) continue;
                if (visited[i][j]) continue;
                    cnt ++;
                    dfs(i, j);
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans;


}