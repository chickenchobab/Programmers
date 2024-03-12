#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m, h;
bool map[33][11];

int ans;

void input(){
    fastio
    cin >> n >> m >> h;
    int a, b;
    for (int i = 0; i < m; i ++){
        cin >> a >> b;
        map[a][b] = 1;
    }
    ans = 4;
}

bool check(){

    for (int j = 1; j <= n; j ++){
        int col = j;
        for (int i = 1; i <= h; i ++){
            if (map[i][col]) col ++;
            else if (map[i][col - 1]) col --;
        }
        if (col != j) return false;
    }
    return true;
}

void dfs(int chance, int cnt){

    if (chance == cnt){
        if (check()) {
        ans = cnt;
        return;
        }
        return;
    }


    for (int j = 1; j < n; j ++){
        for (int i = 1; i <= h; i ++){
            if (map[i][j] || map[i][j + 1] || map[i][j - 1]) continue;
            map[i][j] = 1;
            dfs(chance, cnt + 1);
            map[i][j] = 0;

            while(!map[i][j - 1] && !map[i][j + 1]) i ++;
        }
    }
}

int main(){
    input();

    for (int i = 0; i < 4; i ++){
        dfs(i, 0);
        if (ans < 4) {
            cout << ans;
            return 0;
        }
    }

    cout << -1;

    return 0;
}