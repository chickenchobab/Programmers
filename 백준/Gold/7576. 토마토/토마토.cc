#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

int m, n, wall, cnt, ans;
int map[1001][1001];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
queue<ii> q;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> map[i][j];
            if (map[i][j] == 1) {
                q.push({i, j});
                cnt ++;
            }
            else if (map[i][j] == -1) {
                wall ++;
            }
        }
    }
}

int bfs(){

    while(q.size()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d ++){

            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni < 1 || ni > m || nj < 1 || nj > n) continue;
            if (map[ni][nj]) continue;

            // cout << ni << ' ' << nj << endl;
            q.push({ni, nj});
            map[ni][nj] = map[i][j] + 1;
            cnt ++;
            ans = max(ans, map[i][j]);
        }
    }

    if (cnt == m * n - wall)
        return ans;
    return -1;
}

int main(){
    input();
    cout << bfs();
}