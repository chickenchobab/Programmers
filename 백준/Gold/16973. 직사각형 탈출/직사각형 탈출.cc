#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int h, w, si, sj, fi, fj;
int map[1001][1001];

typedef pair<int, int> p;
int visited[1001][1001];
int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};

void input(){
    fastio
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> map[i][j];
        }
    }
    cin >> h >> w >> si >> sj >> fi >> fj;
}

void show(){
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool path_check(int ni, int nj){
    if (ni < 1 || ni > n || nj < 1 || nj > m) return false;
    if (map[ni][nj]) return false;
    return true;
}

bool initial_check(){
    for (int i = 0; i < h; i ++){
        for (int j = 0; j < w; j ++){
            int ni = si + i, nj = sj + j;
            if (!path_check(ni, nj)) return false;
        }
    }
    return true;
}



bool check(int ni, int nj, int d){
    if (!path_check(ni, nj)) return false;

    if (d % 2){ // 좌우
        for (int l = 0; l < h; l ++) 
            if (!path_check(ni + l, nj + (d <= 1) * (w - 1))) return false;
    }
    else {
        for (int l = 0; l < w; l ++)
            if (!path_check(ni + (d <= 1) * (h - 1), nj + l)) return false;
    }

    return true;
}

int bfs(){ 
    queue<p> q;

    if (!initial_check()) return -1;

    visited[si][sj] = 1;
    q.push({si, sj});

    while (q.size()){
        int i = q.front().first, j = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d ++){
            int ni = i + di[d], nj = j + dj[d];
            if (visited[ni][nj]) continue;
            if (!check(ni, nj, d)) continue;
            q.push({ni, nj});
            visited[ni][nj] = visited[i][j] + 1;
        }
    }

    if (visited[fi][fj]) return visited[fi][fj] - 1;
    return -1;
}

int main(){
    input();
    cout << bfs();;
    // show();
    return 0;
}