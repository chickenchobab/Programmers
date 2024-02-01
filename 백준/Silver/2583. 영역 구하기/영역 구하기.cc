#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m, n, k;
int map[101][101], visited[101][101];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

typedef pair<int, int> pi;
int cnt;
vector<int> ans;


void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m >> k;
    int a, b, c, d;
    for (int t = 1; t <= k; t ++){
        cin >> a >> b >> c >> d;
        for (int i = a + 1; i <= c; i ++){
            for (int j = b + 1; j <= d; j ++){
                map[j][i] = 1;
            }
        }
    }
}

void bfs(int i, int j){

    queue<pi> q;
    q.push({i, j});
    visited[i][j] = 1;

    while(q.size()){
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d ++){
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
            if (visited[ni][nj] || map[ni][nj]) continue;
            cnt ++;
            visited[ni][nj] = 1;
            q.push({ni, nj});
        }
    }
}

int main(){
    
    input();
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (map[i][j] || visited[i][j]) continue;
            cnt = 1;
            bfs(i, j);
            ans.push_back(cnt);
        }
    }
    sort(ans.begin(), ans.end());

    // for (int i = 1; i <= n; i ++){
    //     for (int j = 1; j <= m; j ++){
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << ans.size() << '\n';
    for (int tmp : ans){
        cout << tmp << ' ';
    }

}