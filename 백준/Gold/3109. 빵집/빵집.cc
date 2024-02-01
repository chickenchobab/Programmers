#include <iostream>
using namespace std;

int r, c, ans;
int map[10001][505];
int di[3] = {-1, 0, 1,};

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> r >> c;
    string str;
    for (int i = 1; i <= r; i ++){
        cin >> str;
        for (int j = 1; j <= c; j ++){
            map[i][j] = (str[j - 1] == 'x' ? 1 : 0);
        } 
    } 
}
int dfs(int i, int j){
    
    if (j == c) {
        return 1;
    }
    map[i][j] = -1;
    for (int d = 0; d < 3; d ++){
        int ni = i + di[d];
        int nj = j + 1;
        if (ni < 1 || ni > r || nj < 1 || nj > c) continue;
        if (map[ni][nj]) continue;
        // cout << ni << ' ' << nj << '\n';
        if (dfs(ni, nj)) return 1;
    }
    return 0;
}

int main(){

    input();

    for (int i = 1; i <= r; i ++){
        // cout << i << ' ' << 1 << '\n';
        ans += dfs(i, 1);
    }

    cout << ans;
}