#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
int n, node, dist;
vector<ii> g[10001];
int visited[10001];


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int a, b, c;
    for (int i = 1; i <= n - 1; i ++){
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
}

void reset(){
    for (int i = 1; i <= n; i ++)
        visited[i] = 0;
    dist = 0;
}

void dfs(int u, int d){
    if (d > dist){
        dist = d;
        node = u;
    }
    visited[u] = 1;
    for (ii tmp : g[u]){
        int v = tmp.first;
        if (visited[v]) continue;
        dfs(v, d + tmp.second);
    }
}

int main(){
    input();
    dfs(1, 0);
    reset();
    dfs(node, 0);
    cout << dist;
}