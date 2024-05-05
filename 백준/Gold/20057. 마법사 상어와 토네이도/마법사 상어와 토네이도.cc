#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;
int map[500][500];
int offset[4][9][2] = {{{-1, -1}, {-1, 1}, {-2, 0}, {0, 1}, {0, 2}, {0, -1}, {0, -2}, {1, 1}, {1, -1}},
                        {{1, -1}, {-1, -1}, {0, -2}, {-1, 0}, {-2, 0}, {1, 0}, {2, 0}, {-1, 1}, {1, 1}},
                        {{1, 1}, {1, -1}, {2, 0}, {0, -1}, {0, -2}, {0, 1}, {0, 2}, {-1, -1}, {-1, 1}},
                        {{-1, 1}, {1, 1}, {0, 2}, {1, 0}, {2, 0}, {-1, 0}, {-2, 0}, {1, -1}, {-1, -1}}};
float portion[9] = {0.1, 0.1, 0.05, 0.07, 0.02, 0.07, 0.02, 0.01, 0.01};
int di[] = {-1, 0, 1, 0}, dj[] = {0, -1, 0, 1};
int ans;

void input(){
    fastio
    cin >> n;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> map[i][j];
        }
    }
}

void spread(int i, int j, int dir){
    int ni, nj, sum = 0;
    float move;
    for (int near = 0; near < 9; near ++){
        ni = i + offset[dir][near][0];
        nj = j + offset[dir][near][1];
        move = portion[near] * map[i][j];
        sum += (int) move;
        if (ni < 1 || ni > n || nj < 1 || nj > n) ans += (int) move;
        else map[ni][nj] += (int) move;
    }
    map[i][j] -= sum;

    ni = i + di[dir];
    nj = j + dj[dir];
    if (ni < 1 || ni > n || nj < 1 || nj > n) ans += map[i][j];
    else map[ni][nj] += map[i][j];
    map[i][j] = 0;
}

void solve(){
    int i, j, turn, spd, dir;
    turn = n - 1; 
    i = (n + 1) / 2; j = (n + 1) / 2; spd = 1; dir = 1;
    while (turn --){
        for (int t = 1; t <= 2; ++ t){
            for (int s = 1; s <= spd; ++ s){
                i = i + di[dir];
                j = j + dj[dir];
                if (map[i][j]) spread(i, j, dir);
            }
            dir = (dir + 1) % 4;
        }
        spd ++;
    }
    for (int s = 1; s <= spd - 1; ++ s){
        i = i + di[dir];
        j = j + dj[dir];
        if (map[i][j]) spread(i, j, dir);
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}