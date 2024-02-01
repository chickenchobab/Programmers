#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[101][101], visited[101][101];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
typedef pair<int, int> p;

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> map[i][j];
        }
    }
}

// 외부 공기는 -1 표시
void init(){
    queue<p> q;
    visited[1][1] = 1;
    q.push({1, 1});
    while (q.size()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d ++){
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
            if (visited[ni][nj] || map[ni][nj]) continue;
            map[ni][nj] = -1;
            visited[ni][nj] = 1;
            q.push({ni, nj});
        }
    }
}

void reset(){
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            visited[i][j] = 0;
        }
    }
}

void find_edge(int i, int j){
    int cnt = 0;
    visited[i][j] = 1; 
    for (int d = 0; d < 4; d ++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
        if (map[ni][nj] == -1) cnt ++;
        if (map[ni][nj] || visited[ni][nj]) continue;
        find_edge(ni, nj);
    }
    if (cnt >= 2) visited[i][j] = -1;
}

void find_air(int i, int j){
    map[i][j] = -1;
    for (int d = 0; d < 4; d ++){
        int ni = i + di[d], nj = j + dj[d];
        if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
        if (map[ni][nj]) continue;
        find_air(ni, nj);
    }
}

void melt(int i, int j){
    visited[i][j] = 0;
    map[i][j] = -1;
    for (int d = 0; d < 4; d ++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
        if (map[ni][nj] == 0) {
            find_air(ni, nj);
            continue;
        }
        if (visited[ni][nj] != -1) continue;
        melt(ni, nj);
    }
}

bool solve(){
    bool cheese = false;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (map[i][j] != 1) continue;
            cheese = true;
            find_edge(i, j);
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (visited[i][j] != -1) continue;
            melt(i, j);
        }
    }
    
    reset();

    return cheese;
}

int main(){
    input();
    init();
    int ans = 0;
    while(int tmp = solve()){
        ans += tmp;
    }
    cout << ans;
}