#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, node, dist;
typedef pair<int, int> ii;
vector<ii> g[100001];
int visited[100001];

void input(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int i, j, d;
    for (int t = 1; t <= n; t ++){
        cin >> i;
        while(1){
            cin >> j;
            if (j == -1) break;
            cin >> d;
            g[i].push_back({j, d});
        }
    }
}
void reset(){
    for (int i = 1; i <= n; i ++) 
        visited[i] = 0;
    dist = 0;
}

void dfs(int u, int d){

    if (dist < d){
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
    //cout << node << ' ' << dist << '\n';
    reset();
    dfs(node, 0);
    cout << dist;

    return 0;
}