#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int h, w, si, sj, fi, fj;
int map[1001][1001];

typedef pair<int, int> p;
bool visited[1001][1001];
int wall[1001][1001];
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

    wall[1][1] = map[1][1];
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            wall[i][j] = map[i][j] - wall[i - 1][j - 1] + wall[i - 1][j] + wall[i][j - 1];
        }
    }
}

bool path_check(int i1, int j1, int i2, int j2){
    if (wall[i2][j2] - wall[i1 - 1][j2] - wall[i2][j1 - 1] + wall[i1 - 1][j1 - 1]) return false;
    return true;
}

bool range_check(int ni, int nj){
    if (ni < 1 || ni > n || nj < 1 || nj > m) return false;
    return true;
}

bool check(int i, int j){
    if (!range_check(i, j) || !range_check(i + h - 1, j + w - 1)) return false;
    if (!path_check(i, j, i + h - 1, j + w - 1)) return false;
    return true;
}

int bfs(){ 
    queue<pair<p, int>> q;

    if (!check(si, sj)) return -1;

    visited[si][sj] = 1;
    q.push({{si, sj}, 0});

    while (q.size()){
        int i = q.front().first.first, j = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (i == fi && j == fj) return dist;

        for (int d = 0; d < 4; d ++){
            int ni = i + di[d], nj = j + dj[d];
            if (visited[ni][nj]) continue;
            if (!check(ni, nj)) continue;
            q.push({{ni, nj}, dist + 1});
            visited[ni][nj] = 1;
        }
    }

    return -1;
}

int main(){
    input();
    cout << bfs();;
    return 0;
}