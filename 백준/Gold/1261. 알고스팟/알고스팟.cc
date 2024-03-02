#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
bool map[101][101];

int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
int visited[101][101];
typedef pair<int, int> p;
queue<p> q;

void input(){
    fastio
    cin >> m >> n;
    string str;
    for (int i = 1; i <= n; i ++){
        cin >> str;
        for (int j = 1; j <= m; j ++){
            map[i][j] = str[j - 1] - '0';
            visited[i][j] = -1;
        }
    }
}

void bfs(){

    q.push({1, 1});
    visited[1][1] = 0;

    while (q.size()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d ++){
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
            if (visited[ni][nj] == -1) 
                    visited[ni][nj] = visited[i][j] + map[ni][nj];
            else {
                if (visited[ni][nj] <= visited[i][j] + map[ni][nj]) continue;
                visited[ni][nj] = visited[i][j] + map[ni][nj];
            }
            q.push({ni, nj});
        }
    }
}

int main(){
    input();
    bfs();
    cout << visited[n][m];
    return 0;
}