#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int n, m;
int map[102][102];

int visited[102][102];
int di[] = {1, 1, -1, -1, 0, 0}, dj[] = {0, 1, 0, 1, 1, -1};
typedef pair<int, int> p;
int ans = 0;

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> map[i][j];
        }
    }
}

void show(){
    for (int i = 0; i <= n + 1; i ++){
        for (int j = 0; j <= m + 1; j ++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int direction(int i){
    if (i % 2) return 1;
    return -1;
}

void check_outside(){
    queue<p> q;

    visited[0][0] = 1;
    map[0][0] = -1;
    q.push({0, 0});

    while (q.size()){
        int i = q.front().first;
        int j = q.front().second;
        int dir = direction(i);
        q.pop();
        
        for (int d = 0; d < 6; d ++){
            int ni = i + dir * di[d];
            int nj = j + dir * dj[d];
            if (ni < 0 || ni > n + 1 || nj < 0 || nj > m + 1) continue;
            if (map[ni][nj] || visited[ni][nj]) continue;
            map[ni][nj] = -1;
            visited[ni][nj] = 1;
            q.push({ni, nj});
        }
    }
}

void check_building(int i, int j){
    visited[i][j] = 1;

    int dir = direction(i);

    for (int d = 0; d < 6; d ++){
        int ni = i + dir * di[d];
        int nj = j + dir * dj[d];

        if (ni < 0 || ni > n + 1 || nj < 0 || nj > m + 1) continue;
        if (map[ni][nj] == -1) ans ++;

        if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
        if (map[ni][nj] != 1) continue;
        if (visited[ni][nj]) continue;
        check_building(ni, nj);
    }
}

int main(){
    input();
    check_outside();
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (visited[i][j]) continue;
            if (map[i][j] == 0) continue;
            check_building(i, j);
        }
    }

    //show();
    cout << ans;
}