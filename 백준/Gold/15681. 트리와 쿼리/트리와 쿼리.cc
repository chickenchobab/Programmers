#include <iostream>
#include <vector>

using namespace std;

int n, r, q, u, v;
vector<int> edge[100001];
int dp[100001];

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

void dfs(int prv, int cur){
    // if (dp[cur]) return;
    int sum = 1;
    for (int nxt : edge[cur]){
        if (nxt == prv) continue;
        dfs(cur, nxt);
        sum += dp[nxt];
    }
    dp[cur] = sum;
}

void query(){
    while (q --){
        cin >> u;
        cout << dp[u] << '\n';
    }
}

int main(){
    input();
    dfs(0, r);
    query();
}