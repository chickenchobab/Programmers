#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m, x;
vector<int> edge[200002];
int visited[200002];
int ans, cnt, flag;

void input(){
    fastio
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i ++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    cin >> x;
}

void dfs(int cur){
    cnt ++;
    visited[cur] = 1;
    for (int nxt : edge[cur]){
        if (nxt == x) flag ++;
        if (visited[nxt]) continue;
        dfs(nxt);
    }
}

int main(){
    input();
    visited[x] = 1;
    for (int i = 1; i <= n; i ++){
        if (visited[i]) continue;
        cnt = flag = 0;
        dfs(i);
        if (flag > 1) ans = max(ans, cnt);
        else ans = max(ans, cnt + flag);
    }
    cout << ans;
    return 0;
}