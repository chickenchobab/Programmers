#include <iostream>
#include <algorithm>
#define INF 22222222
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int edge[16][16];
int dp[16][1 << 16];

void input(){
    fastio
    cin >> n;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cin >> edge[i][j];
            if (edge[i][j] == 0) edge[i][j] = INF;
        }
    }
}

void reset_table(){
    for (int i = 0; i < n; i ++){
        for (int j = 0; j <= (1 << n) - 1; j ++){
            dp[i][j] = 0;
        }
    }
}

int dfs(int start, int cur, int visited){
    if (visited == (1 << n) - 1) return edge[cur][start];
    
    if (dp[cur][visited]) return dp[cur][visited];

    dp[cur][visited] = INF;
    for (int nxt = 0; nxt < n; nxt ++){
        if (visited & (1 << nxt)) continue;
        if (edge[cur][nxt] == INF) continue;
        dp[cur][visited] = min(dp[cur][visited], dfs(start, nxt, visited | (1 << nxt)) + edge[cur][nxt]);
    }

    return dp[cur][visited];
}

int main(){
    input();
    int ans = INF;
    for (int i = 0; i < n; i ++){
        ans = min(ans, dfs(i, i, 1 << i));
        reset_table();
    }
    cout << ans;
    return 0;
}