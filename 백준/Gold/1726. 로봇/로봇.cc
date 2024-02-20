#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int map[101][101];
int si, sj, sd, fi, fj, fd;

typedef tuple<int, int, int> p;
int visited[101][101][4];
int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0};
queue<p> q;

void input(){
    fastio
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> map[i][j];
        }
    }
    cin >> si >> sj >> sd >> fi >> fj >> fd;
    sd --; fd --;
}

int turn(int d1, int d2){
    if (d1 == d2) return 0;
    if (d1 < 2 && d2 < 2) return 2;
    if (d1 > 1 && d2 > 1) return 2;
    return 1;
}

int bfs(){

    q.push({si, sj, sd});
    visited[si][sj][sd] = 1;

    while (q.size()){
        int i, j, d;
        tie(i, j, d) = q.front();
        q.pop();

        if (i == fi && j == fj && d == fd) return visited[fi][fj][fd] - 1;
        
        for (int str = 1; str <= 3; str ++){
            int ni = i + str * di[d];
            int nj = j + str * dj[d];
            if (ni < 1 || ni > n || nj < 1 || nj > m) break;
            if (map[ni][nj]) break;
            if (visited[ni][nj][d]) continue;
            q.push({ni, nj, d});
            visited[ni][nj][d] = visited[i][j][d] + 1;
        }     

        for (int dir = 0; dir < 4; dir ++){
            if (visited[i][j][dir]) continue;
            q.push({i, j, dir});
            visited[i][j][dir] = visited[i][j][d] + turn(d, dir);
        }
    }
}

int main(){
    input();
    cout << bfs();
    return 0;
}