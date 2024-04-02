#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m, ri, rj, bi, bj;
char map[11][11];
bool visited[11][11][11][11];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
typedef struct NODE{
    int rx, ry, bx, by, time;
    string path = "";
}node;
queue<node> q;

void input(){
    fastio
    cin >> n >> m;
    char ch;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> ch;
            if (ch == '\n') cin >> ch;
            map[i][j] = ch;
            if (ch == 'R') ri = i, rj = j;
            else if (ch == 'B') bi = i, bj = j;
        }
    }
}

char get_dir(int d){
    if (d == 0) return 'D';
    if (d == 1) return 'U';
    if (d == 2) return 'R';
    return 'L';
}

void move(int rx, int ry, int bx, int by, int d, int time, string path) {

    bool rstuck = 0, bstuck = 0;

    while (1) {

        if (map[rx][ry] == 'O' || map[rx + di[d]][ry + dj[d]] == '#' || (rx + di[d] == bx && ry + dj[d] == by)) rstuck = 1;
        else {
            rstuck = 0;
            rx += di[d]; 
            ry += dj[d];
        }
        if (map[bx + di[d]][by + dj[d]] == '#' || (bx + di[d] == rx && by + dj[d] == ry)) bstuck = 1;
        else {
            bstuck = 0;
            bx += di[d];
            by += dj[d];
        }

        if (map[bx + di[d]][by + dj[d]] == 'O' || map[bx][by] == 'O') return;

        if (rstuck && bstuck) {
            if (visited[rx][ry][bx][by] == 0){
                //cout << rx << ' ' << ry << ' ' << bx << ' ' << by << ' ' << d << '\n';
                visited[rx][ry][bx][by] = 1;
                q.push({rx, ry, bx, by, time + 1, path + get_dir(d)});
            }
            return;
        }
    }
}

void bfs(){

    int rx, ry, bx, by, time;
    string path;

    q.push({ri, rj, bi, bj, 0});
    visited[ri][rj][bi][bj] = 1;

    while (q.size()){
        node f = q.front();
        q.pop();
        rx = f.rx, ry = f.ry, bx = f.bx, by = f.by, time = f.time;
        path = f.path;

        if (map[rx][ry] == 'O') {
            cout << time << '\n' << path;
            return;
        }
        if (time == 10) continue;

        for (int d = 0; d < 4; d ++){
            move(rx, ry, bx, by, d, time, path);
        }
    }

    cout << -1;
}

int main(){
    input();
    bfs();
    return 0;
}