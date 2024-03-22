#include <iostream>
#include <algorithm>
#include <tuple>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef pair<int, int> pos;
int map[4][4];
typedef struct FISH{
    int i, j, dir;
    bool alive;
}fish;
fish arr[17];

int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dj[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void input(){
    fastio
    int n, d; 
    for (int i = 0; i < 4; i ++){
        for (int j = 0; j < 4; j ++){
            cin >> n >> d;
            map[i][j] = n;
            arr[n] = {i, j, d - 1, 1};
        }
    }
}

void make_copy(int m1[4][4], int m2[4][4], fish p1[], fish p2[]) {
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            m2[i][j] = m1[i][j];
        }
    }
    for (int i = 1; i <= 16; i ++) 
        p2[i] = p1[i];
}

void set_or_reset(int i, int j, int ni, int nj, int idx, bool flag){
    if (flag) {
        map[i][j] = 0;
        map[ni][nj] = -1;
        arr[idx].alive = 0;
    }
    else {
        map[i][j] = -1;
        map[ni][nj] = idx;
        arr[idx].alive = 1;
    }
}

int dfs(int si, int sj, int sd, int cur){  

    int mapcpy[4][4];
    fish arrcpy[17];
    int i, j, ni, nj, d, nd, res = 0;

    make_copy(map, mapcpy, arr, arrcpy);

    for (int u = 1; u <= 16; u ++){
        
        fish f = arr[u];
        if (f.alive == false) continue;

        i = f.i, j = f.j, d = f.dir;
        nd = d;
        
        int turn_cnt = 8;
        while (turn_cnt --) {
            ni = i + di[nd], nj = j + dj[nd];
            if (ni >= 0 && ni <= 3 && nj >= 0 && nj <= 3 && map[ni][nj] != -1) break;
            nd = (nd + 1) % 8;
        }
        
        if (turn_cnt) {
            int v = map[ni][nj]; 
            arr[u] = {ni, nj, nd, 1};
            arr[v].i = i;
            arr[v].j = j;
            swap(map[i][j], map[ni][nj]);
        }
    }
    
    map[si][sj] = 0;

    for (int w = 1; w <= 3; w ++){
        ni = si + w * di[sd], nj = sj + w * dj[sd];

        if (ni < 0 || ni > 3 || nj < 0 || nj > 3) break;
        if (map[ni][nj] == 0) continue;

        int nxt = map[ni][nj];
        nd = arr[nxt].dir;

        set_or_reset(si, sj, ni, nj, nxt, 1);
        res = max(res, dfs(ni, nj, nd, nxt));
        set_or_reset(si, sj, ni, nj, nxt, 0);
    }

    make_copy(mapcpy, map, arrcpy, arr);
    return cur + res;
}

int main(){
    input();
    int d = arr[map[0][0]].dir;
    int cur = map[0][0];
    set_or_reset(0, 0, 0, 0, map[0][0], 1);
    cout << dfs(0, 0, d, cur);
    return 0;
}