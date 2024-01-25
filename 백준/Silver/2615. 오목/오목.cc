#include <iostream>

using namespace std;

int winner, x, y;
int map[20][20], visited[20][20];
int di[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dj[] = {0, 1, 0, -1, 1, -1, -1, 1};

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 19; i ++){
        for (int j = 1; j <= 19; j ++){
            cin >> map[i][j];
        }
    }
}

bool valid(int i, int j, int ni, int nj){
    if (ni < 1 || ni > 19 || nj < 1 || nj > 19) return false;
    if (map[ni][nj] != map[i][j]) return false;
    return true;
}

void dfs(int si, int sj, int i, int j, int dir, int cnt){

    int ni = i + di[dir];
    int nj = j + dj[dir];
    // cout << si << ' ' << sj << ' ' << i << ' ' << j << ' ' << cnt << '\n';
    bool val = valid(i, j, ni, nj);

    if (cnt == 4 && val == false){ 
        winner = map[si][sj];
        x = si, y = sj;
        return;
    }
    if (val) dfs(si, sj, ni, nj, dir, cnt + 1); 
}

int main(){
    init();
    for (int j = 1; j <= 19; j ++){
        for (int i = 1; i <= 19; i ++){
            if (map[i][j] == 0) continue;
            if (winner) continue;
            for (int d = 0; d < 8; d ++){
                int ni = i + di[d], nj = j + dj[d];
                int pi = i - di[d], pj = j - dj[d];
                if (!valid(i, j, ni, nj)) continue;
                if (valid(i, j, pi, pj)) continue;
                dfs(i, j, ni, nj, d, 1);
            }
        }
    }
    cout << winner;
    if (winner) cout << '\n' << x << ' ' << y;
}