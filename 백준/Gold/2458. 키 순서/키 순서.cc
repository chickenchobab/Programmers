#include <iostream>

using namespace std;

int n, m, s, d, ans;
int map[501][501];
int visited[501], cnt[501];

void reset(){
    for (int i=1; i<=n; i++)
        visited[i] = 0;
}

void dfs(int u){
    visited[u] = 1;
    for (int v=1; v<=n; v++){
        if (map[u][v] != d) continue;
        if (visited[v]) continue;
        cnt[s] ++;
        dfs(v);
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;

    int a, b;
    for (int i=1; i<=m; i++){
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = -1;
    }

    for (s=1; s<=n; s++){
        d = 1;
        dfs(s);
        reset();
        d = -1;
        dfs(s);
        reset();
    }

    for (int i=1; i<=n; i++){
        //cout << cnt[i] << ' '; 
        if (cnt[i] == n-1) {
            ans++;
        }
    }

    //cout << endl;
    cout << ans;

}