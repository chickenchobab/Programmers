#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m, cnt, ans;
int height[301][301];

int visited[301][301];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void input(){
    fastio
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> height[i][j];
        }
    }
}

void show(){
    cout << cnt << '\n';
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cout << height[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void check_ice(int i, int j){
    visited[i][j] = 1;
    for (int d = 0; d < 4; d ++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
        if (height[ni][nj] == 0) {
            visited[i][j] ++;
            continue;
        }
        if (visited[ni][nj]) continue;
        check_ice(ni, nj);
    }
}

void melt_ice(){

    cnt = 0;

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            visited[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (!height[i][j] || visited[i][j]) continue;
            cnt ++;
            check_ice(i, j);
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (!height[i][j]) continue;
            height[i][j] = max(height[i][j] - (visited[i][j] - 1), 0);
        }
    }

    ans ++;
}

int main(){
    input();

    while(1){
        melt_ice();
        //show();
        if (cnt > 1) {
            cout << ans - 1;
            return 0;
        }
        if (cnt == 0){
            cout << 0;
            return 0;
        }

    }
}