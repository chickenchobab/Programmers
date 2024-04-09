#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 20
using namespace std;

int n;
int map[MAX + 1][MAX + 1];
int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};
int x, y, time, lev, cnt;
typedef struct NODE{
    int dist, i, j;
}node;

void input(){
    fastio
    cin >> n;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> map[i][j];
            if (map[i][j] == 9) {
                x = i;
                y = j;
                map[i][j] = 0;
            }
        }
    }
}

bool cmp(node a, node b){
    if (a.dist == b.dist){
        if (a.i == b.i) return a.j < b.j;
        return a.i < b.i;
    }
    return a.dist < b.dist;
}

void show_map(){
    cout << '\n';
    cout << lev << '\n';
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool find_fish(){

    int i, j, ni, nj, dist;
    // int min_dist = MAX * MAX, min_i = MAX, min_j = MAX;

    bool visited[n + 1][n + 1] = {0,};
    queue<node> q;
    vector<node> fishes;

    visited[x][y] = 1;
    q.push({0, x, y});

    while (q.size()){
        node f = q.front();
        q.pop();
        i = f.i, j = f.j, dist = f.dist;

        if (map[i][j] > 0 && map[i][j] < lev) {
            fishes.push_back({dist, i, j});
        }

        for (int dir = 0; dir < 4; dir ++){
            ni = i + di[dir];
            nj = j + dj[dir];
            if (ni < 1 || ni > n || nj < 1 || nj > n) continue;
            if (visited[ni][nj]) continue;
            if (map[ni][nj] > lev) continue;
            visited[ni][nj] = 1;
            q.push({dist + 1, ni, nj});
        }
    }

    sort(fishes.begin(), fishes.end(), cmp);

    if (fishes.empty()) return false;
    node f = fishes.front();
    x = f.i, y = f.j;
    time += f.dist;
    cnt ++;
    map[x][y] = 0;
    return true;
}


void solve(){
    lev = 2;
    while (find_fish()) {
        if (lev == cnt){
            lev ++;
            cnt = 0;
        }
        // show_map();
    }
    cout << time;
}


int main(){
    input();
    solve();
    return 0;
}