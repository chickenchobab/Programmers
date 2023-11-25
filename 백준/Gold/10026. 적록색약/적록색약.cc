#include <iostream>

using namespace std;

int n, cnt1, cnt2;
char map[101][101];
int visited[101][101], di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

bool same(char a, char b){
    if ( a == b ) return true;
    if (a == 'R' || a == 'G') {
        if (b == 'R' || b == 'G') return true;
    }
    return false;
}

void dfs1(int i, int j){
    visited[i][j] = 1;
    for (int d=0; d<4; d++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni<1 || ni>n || nj<1 || nj>n) continue;
        if (visited[ni][nj]) continue;
        if (map[ni][nj] != map[i][j]) continue;
        dfs1(ni, nj);
    }
}

void dfs2(int i, int j){
    visited[i][j] = 1;
    for (int d=0; d<4; d++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni<1 || ni>n || nj<1 || nj>n) continue;
        if (visited[ni][nj]) continue;
        if (same(map[i][j], map[ni][nj]))
        dfs2(ni, nj);
    }
}

int main(){
    cin >> n;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (visited[i][j] == 0){
                cnt1 ++;
                dfs1(i,j);
            }
        }
    }

    for (int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            visited[i][j] = 0;
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (visited[i][j] == 0){
                cnt2 ++;
                dfs2(i,j);
            }
        }
    }

    cout << cnt1 << ' ' << cnt2;


}