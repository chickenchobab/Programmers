#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int map[1001][1001], visited[1001][1001];
int gi, gj;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1}; 
typedef struct NODE{
    int i, j;
}node;
queue<node> q;

void input(){
    fastio
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            visited[i][j] = -1;
            cin >> map[i][j];
            if (map[i][j] == 0) visited[i][j] = 0;
            else if (map[i][j] == 2){
                gi = i, gj = j;
            } 
        }
    }
}

void bfs(){
    q.push({gi, gj});
    visited[gi][gj] = 0;

    while (q.size()){
        node f = q.front();
        q.pop();

        int i = f.i, j = f.j;
        for (int d = 0; d < 4; d ++){
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
            if (visited[ni][nj] != -1) continue;
            if (map[ni][nj] == 0) continue;
            q.push({ni, nj});
            visited[ni][nj] = visited[i][j] + 1;
        }
    }
}

void solve(){
    bfs();
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    input();
    solve();
    return 0;
}