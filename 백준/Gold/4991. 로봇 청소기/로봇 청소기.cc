#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>
#define MAX 444

using namespace std;

int w, h;
int map[21][21];

typedef pair<int, int> p;
int cnt, ans, status;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

int vis[21][21], graph[11][11], dp[11][1 << 11];

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void reset(){
    cnt = 1, ans = MAX, status = 0;
    memset(dp, 0, sizeof(dp));
    memset(graph, 0, sizeof(graph));
}

bool input(){
    cin >> w >> h;
    if (w == 0 && h == 0) return false;

    reset();
    char ch;
    for (int i = 1; i <= h; i ++){
        for (int j = 1; j <= w; j ++){
            cin >> ch;
            while (ch == '\n' || ch == ' ') cin >> ch;

            if (ch == 'o') map[i][j] = 1;
            else if (ch == '*') map[i][j] = ++ cnt;
            else if (ch == '.') map[i][j] = 0;
            else map[i][j] = -1;
        }
    }
    return true;
}

void bfs(int i, int j, int idx){
    queue<p> q;
    int nxt_idx;
    memset(vis, 0, sizeof(vis));

    q.push({i, j});
    vis[i][j] = 1;

    while (q.size()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d ++){
            int ni = i + di[d], nj = j + dj[d];
            if (ni < 1 || ni > h || nj < 1 || nj > w) continue;
            if (vis[ni][nj]) continue;
            if ((nxt_idx = map[ni][nj]) == -1) continue;

            if (nxt_idx > idx){
                graph[idx - 1][nxt_idx - 1] = graph[nxt_idx - 1][idx - 1] = vis[i][j];
            }
            q.push({ni, nj});
            vis[ni][nj] = vis[i][j] + 1;
        }
    }
}

int dfs(int cur, int visited){

    status = max(status, visited);

    if (visited == (1 << cnt) - 1)
        return 0;

    if (dp[cur][visited])
        return dp[cur][visited];

    dp[cur][visited] = MAX;
    for (int nxt = 1; nxt < cnt; nxt ++){
        if (visited & (1 << nxt)) continue;
        if (graph[cur][nxt] == 0) continue;
        dp[cur][visited] = min(dp[cur][visited], dfs(nxt, visited | (1 << nxt)) + graph[cur][nxt]);
    }

    return dp[cur][visited];
}

void make_graph(){
    for (int i = 1; i <= h; i ++){
        for (int j = 1; j <= w; j ++) {
            if (map[i][j] > 0) bfs(i, j, map[i][j]);
        }
    }
}

void show_graph(){
    for (int i = 0; i < cnt; i ++){
        for (int j = 0; j < cnt; j ++) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    init();
    while (1){
        if(!input()) break;
        make_graph();
        // show_graph();

        ans = dfs(0, 1);
        status == (1 << cnt) - 1 ? cout << ans : cout << -1;
        cout << '\n';
    }
    return 0;
}