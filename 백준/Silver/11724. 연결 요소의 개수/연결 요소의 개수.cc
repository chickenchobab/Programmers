#include <iostream>
#include <vector>

using namespace std;

int n, m, u, v, cnt;
int visited[1001];
vector<int> g[1001];

void dfs(int u){
    for(int v : g[u]){
        if(visited[v]) continue; 
        else {
            visited[v] = 1;
            dfs(v);
        } 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    for (int i=1; i<=m; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i=1; i<=n; ++i){
        
        if(!visited[i]) {
            visited[i] = 1;
            dfs(i);
            cnt ++;
        }
    }

    cout << cnt;
}