#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m, total;
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

int bfs(){
    queue<p> q;
    int visited[101][101] = {0,};

    q.push({1, 1});
    visited[1][1] = 1;

    int melted = 0;

    while (q.size()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d ++){
            int ni = i + di[d], nj = j + dj[d];
            if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
            if (visited[ni][nj]) continue;
            if (map[ni][nj] == 1){
                map[ni][nj] = -1;
                //cout << ni << ' ' << nj << '\n';
                melted ++;
                continue;
            }
            if (map[ni][nj] == 0) {
                visited[ni][nj] = 1;
                q.push({ni, nj});
            }
        }
    }

    if (melted == 0) return 0;

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (map[i][j] == -1){
                map[i][j] = 0;
            }
        }
    }
    return melted;
}

int main(){
    input();
    int ans = 100 * 100, cnt = 0;
    while(total > 0){
        if (int melted = bfs()){
            cnt ++;
            ans = min(ans, total);
            total -= melted;
            //cout << total << ' ' << melted << '\n';
        }
    }
    cout << cnt << '\n' << ans;
    return 0;
}