#include <iostream>
#include <vector>

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

int main(){
    cin >> n;

    int a, b;

    for (int i=1; i<=n-1; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);

    for (int i=2; i<=n; i++){
        cout << parent[i] << '\n';
    }


}