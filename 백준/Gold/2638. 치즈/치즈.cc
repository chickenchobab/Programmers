#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[101][101];
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

// 점이 엣지인지 확인한다
bool find_edge(int i, int j){
    int cnt = 0;
    for (int d = 0; d < 4; d ++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (map[ni][nj] == -1) cnt ++;
    }
    if (cnt >= 2) return true;
    return false;
}

// 내부 공기를 외부 공기로 바꾼다
void change_air(int i, int j){
    map[i][j] = -1;
    for (int d = 0; d < 4; d ++){
        int ni = i + di[d], nj = j + dj[d];
        if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
        if (map[ni][nj]) continue;
        change_air(ni, nj);
    }
}

bool solve(){
    bool cheese = false;

    queue<p> q;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (map[i][j] != 1) continue;
            if (find_edge(i, j)) {
                q.push({i, j});
                cheese = true;
            }
        }
    }

    while(q.size()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        map[i][j] = -1;
        for (int d = 0; d < 4; d ++){
            int ni = i + di[d], nj = j + dj[d];
            if (map[ni][nj]) continue;
            change_air(ni, nj);
        }
    }

    return cheese;
}

int main(){
    input();
    change_air(1, 1);
    int ans = 0;
    while(int tmp = solve()){
        ans += tmp;
    }
    cout << ans;
}