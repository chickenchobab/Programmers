#include <iostream>
#include <vector>
using namespace std;

int n, m, s, cnt, ans;
vector<int> e1[501], e2[502];
int visited[501];

void reset(){
    for (int i=1; i<=n; i++)
        visited[i] = 0;
}

void dfs(int u, vector<int> *e){
    visited[u] = 1;
    for (int v : e[u]){
        if (visited[v]) continue;
        cnt ++;
        dfs(v, e);
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    int a, b;
    for (int i=1; i<=m; i++){
        cin >> a >> b;
        e1[a].push_back(b);
        e2[b].push_back(a);
    }

    for (s=1; s<=n; s++){
        cnt = 0;
        dfs(s, e1);
        reset();
        dfs(s, e2);
        reset();
        if (cnt == n-1) ans++;
    }

    //cout << endl;
    cout << ans;

}