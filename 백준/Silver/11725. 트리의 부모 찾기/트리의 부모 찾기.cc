#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> g[100001];
int visited[100001], parent[100001];

void dfs(int u){
    visited[u] = 1;
    for(int v : g[u]){
        if (visited[v]) continue;
        parent[v] = u;
        dfs(v);
    }
}

void bfs(){
    queue<int> q;
    visited[1] = 1;
    q.push(1);
    while(q.size()){
        int u = q.front();
        q.pop();
        for (int v : g[u]){
            if (visited[v]) continue;
            parent[v] = u;
            visited[v] = 1;
            q.push(v);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int a, b;

    for (int i=1; i<=n-1; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs();

    for (int i=2; i<=n; i++){
        cout << parent[i] << '\n';
    }


}