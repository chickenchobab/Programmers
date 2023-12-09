#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k, a, b, c, d, cnt;
int map[101][101], visited[101][101];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
vector<int> v;

void dfs(int i, int j){
    visited[i][j] = 1;
    for (int d=0; d<4; d++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni<1 || ni>m || nj<1 || nj>n) continue;
        if (visited[ni][nj] || map[ni][nj]) continue;
        dfs(ni, nj);
        cnt ++;
    }
}

int main(){
    cin >> m >> n >> k;

    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            map[i][j] = visited[i][j] = 0;
        }
    }

    for (int i=1; i<=k; i++){
        cin >> a >> b >> c >> d;
        for (int x=b; x<d; x++){
            for (int y=a; y<c; y++){
                map[x+1][y+1] ++;
            }
        }
    }

    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (visited[i][j] || map[i][j]) continue;
            cnt = 1;
            dfs(i, j);
            v.push_back(cnt);
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (int tmp : v){
        cout << tmp << ' ';
    }
}