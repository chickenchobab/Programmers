#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

// sum of the opposite side is 6
int n, m, x, y, nx, ny, k;
int map[20][20];
int di[] = {0, 0, 0, -1, 1}, dj[] = {0, 1, -1, 0, 0};
int dice[7];

void input(){
    fastio
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            cin >> map[i][j];
        }
    }
}

void roll_the_dice(int dir){
    int tmp = dice[1];
    x = nx;
    y = ny;
    switch(dir){
        case 1:
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = tmp;
            break;
        case 2:
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = tmp;
            break;
        case 3:
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = tmp;
            break;
        case 4:
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = tmp;
    }
}

void solve(){

    int dir;

    while (k --){
        cin >> dir;
        nx = x + di[dir];
        ny = y + dj[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        roll_the_dice(dir);

        if (map[x][y]) {
            dice[6] = map[x][y];
            map[x][y] = 0;
        }
        else {
            map[x][y] = dice[6];
        }
        cout << dice[1] << '\n';
    }
}

int main(){
    input();
    solve();
    return 0;
}