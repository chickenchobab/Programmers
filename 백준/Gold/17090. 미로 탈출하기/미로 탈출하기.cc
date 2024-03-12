#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m, ans;
char map[501][501];

int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};



void check(int i, int j){

    bool con = 0;
    char c = map[i][j];
    con += (i == 1 && c == 'U');
    con += (i == n && c == 'D');
    con += (j == 1 && c == 'L');
    con += (j == m && c == 'R');
    if (con) {
        map[i][j] = 'O';
        ans ++;
    }
}

void input(){
    fastio
    cin >> n >> m;
    string str;
    for (int i = 1; i <= n; i ++){
        cin >> str;
        for (int j = 1; j <= m; j ++){
            map[i][j] = str[j - 1];
            check(i, j);
        }
    }
}

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});

    while(!q.empty()){
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for(int d = 0; d < 4; d ++){
            int ni = i + di[d];
            int nj = j + dj[d];
            if(ni < 1 || ni > n || nj < 1 || nj > m) continue;
            if(map[ni][nj] == 'O') continue;
            if(d == 0 && map[ni][nj] != 'D') continue;
            if(d == 1 && map[ni][nj] != 'L') continue;
            if(d == 2 && map[ni][nj] != 'U') continue;
            if(d == 3 && map[ni][nj] != 'R') continue;
            
            q.push({ni, nj}); 
            ans ++;
        }
    }
    
}


int main(){
    input();

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (map[i][j] == 'O') bfs(i, j);
        }
    }
    cout << ans;

    return 0;
}