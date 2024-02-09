#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int n, m;
int map[102][102];

bool visited[102][102];
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

int direction(int i){
    if (i % 2) return 1;
    return -1;
}

void check_from_outside(){
    queue<p> q;

    visited[0][0] = 1;
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
            if (map[ni][nj]) ans ++;
                
            if (map[ni][nj] || visited[ni][nj]) continue;
            visited[ni][nj] = 1;
            q.push({ni, nj});
        }
    }
}

int main(){
    input();
    check_from_outside();
    cout << ans;
}