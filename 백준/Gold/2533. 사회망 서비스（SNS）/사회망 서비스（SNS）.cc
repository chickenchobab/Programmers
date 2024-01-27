#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> edge[1000001];
int visited[1000001];
int dp[1000001][2];


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i ++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}

void dfs(int u){
    visited[u] = 1;
    dp[u][1] = 1;
    for (int v : edge[u]){
        if (visited[v]) continue;
        dfs(v);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][1], dp[v][0]);
    }
}

int main(){
    input();
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
}