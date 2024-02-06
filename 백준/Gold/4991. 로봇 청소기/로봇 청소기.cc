#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int w, h;
int map[21][21];

typedef pair<int, int> p;
int idx, ans;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

vector<p> edge[12];
int visited[12];

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool input(){
    cin >> w >> h;
    if (w == 0 && h == 0) return false;
    idx = 1, ans = 444;
    char ch;
    for (int i = 1; i <= h; i ++){
        for (int j = 1; j <= w; j ++){
            cin >> ch;
            if (ch == '\n') cin >> ch;
            
            if (ch == '.') map[i][j] = 0;
            else if (ch == 'o') map[i][j] = 1;
            else if (ch == 'x') map[i][j] = -1;
            else map[i][j] = ++ idx;
        }
    }
    for (int i = 1; i <= 11; i ++) {
        visited[i] = 0;
        edge[i].clear();
    }
    return true;
}

void show(){
    for (int i = 1; i <= 12; i ++){
        cout << i << ": ";
        for (p tmp : edge[i]){
            cout << "{ distance " << tmp.first << " to " << tmp.second << "} ";
        }
        cout << '\n';
    }
}

void bfs(int i, int j, int index){
    queue<p> q;
    int visited[21][21];
    for (int i = 1; i <= h; i ++){
        for (int j = 1; j <= w; j ++){
            visited[i][j] = 0;
        }
    }
    
    q.push({i, j});
    visited[i][j] = 1;
    while (q.size()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d ++){
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni < 1 || ni > h || nj < 1 || nj > w) continue;
            if (visited[ni][nj]) continue;
            if (map[ni][nj] == -1) continue;
            if (map[ni][nj] > index) {
                edge[index].push_back({visited[i][j], map[ni][nj]});
                edge[map[ni][nj]].push_back({visited[i][j], index});
            }
            q.push({ni, nj});
            visited[ni][nj] = visited[i][j] + 1;
        }
    }
}

void dfs(int cur, int cnt, int dist){
    if (cnt == idx) ans = min(ans, dist);
    for (p tmp : edge[cur]){
        int nxt = tmp.second;
        if (visited[nxt]) continue;
        visited[nxt] = 1;
        dfs(nxt, cnt + 1, dist + tmp.first);
        visited[nxt] = 0;
    }
}

int main(){
    init();
    while (1){
        if(!input()) break;
        for (int i = 1; i <= h; i ++){
            for (int j = 1; j <= w; j ++){
                if (map[i][j] >= 1) bfs(i, j, map[i][j]);
            }
        }
        // show();
        visited[1] = 1;
        dfs(1, 1, 0);
        ans == 444 ? cout << -1 : cout << ans;
        cout << '\n';
    }
    return 0;
}