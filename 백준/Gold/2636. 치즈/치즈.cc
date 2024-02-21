#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m, total, melted;
int map[101][101];

typedef pair<int, int> p;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void input(){
    fastio
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> map[i][j];
            if (map[i][j]) total ++;
        }
    }
}

void bfs(){
    queue<p> q;
    int visited[101][101] = {0,};

    q.push({1, 1});
    visited[1][1] = 1;
    while (q.size()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d ++){
            int ni = i + di[d], nj = j + dj[d];
            if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
            if (visited[ni][nj]) continue;
            if (map[ni][nj] == 1){
                map[ni][nj] = 0;
                melted ++;
            }
            else if (map[ni][nj] == 0) {
                q.push({ni, nj});
            }
            visited[ni][nj] = 1;
        }
    }
}

int main(){
    input();
    int cnt = 0;
    while(total){
        melted = 0;
        bfs();
        cnt ++;
        total -= melted;
    }
    cout << cnt << '\n' << melted;
    return 0;
}