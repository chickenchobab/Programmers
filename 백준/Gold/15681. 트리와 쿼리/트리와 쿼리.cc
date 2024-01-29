#include <iostream>
#include <vector>

using namespace std;

int n, r, q, u, v;
vector<int> edge[100001];
int dp[100001], visited[100001];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i ++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
}

int dfs(int cur){
    if (dp[cur]) return dp[cur];
    int sum = 1;
    visited[cur] = 1;
    for (int nxt : edge[cur]){
        if (visited[nxt]) continue;
        sum += dfs(nxt);
    }
    return (dp[cur] = sum);
}

void query(){
    while (q --){
        cin >> u;
        cout << dp[u] << '\n';
    }
}

int main(){
    input();
    dfs(r);
    query();
}