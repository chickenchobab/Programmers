#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m, ans;
int map[51][51];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
vector<pair<int, int>> pos;
typedef struct NODE{
    int i, j, dist;
}node;

void input(){
    fastio
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> map[i][j];
            if (map[i][j] == 2) pos.push_back({i, j});
        }
    }
    ans = 50 * 50 * 13;
}

int bfs(){
    queue<node> q;
    bool visited[n + 1][n + 1] = {0,};
    int i, j, dist, sum = 0;

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            if (map[i][j] == 3) {
                q.push({i, j, 0});
                visited[i][j] = 1;
            }
        }
    }

    while (q.size()){
        node f = q.front();
        i = f.i, j = f.j, dist = f.dist;
        q.pop();

        if (map[i][j] == 1) sum += dist;

        for (int d = 0; d < 4; d ++){
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni < 1 || ni > n || nj < 1 || nj > n) continue;
            if (visited[ni][nj]) continue;
            visited[ni][nj] = 1;
            q.push({ni, nj, dist + 1});
        }
    }
    
    return sum;
}

void select(int cur, int cnt){
    
    if (cnt == m) {
        ans = min(ans, bfs());
        return;
    }

    for (int nxt = cur + 1; nxt < pos.size(); nxt ++)
    {   map[pos[nxt].first][pos[nxt].second] = 3;
        select(nxt, cnt + 1);
        map[pos[nxt].first][pos[nxt].second] = 2;
    }
}

int main(){
    input();
    for (int cur = 0; cur < pos.size(); cur ++){
        map[pos[cur].first][pos[cur].second] = 3;
        select(cur, 1);
        map[pos[cur].first][pos[cur].second] = 2;
    }
    cout << ans;
    return 0;
}