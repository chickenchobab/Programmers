#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> edge[20002];
int visited[20002];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i ++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}

int bfs(){
    int ans = 0;
    queue<int> q;

    q.push(1);
    visited[1] = 1;

    while (q.size()){
        int u = q.front();
        q.pop();

        for (int v : edge[u]){
            if (visited[v]) continue;
            q.push(v);
            visited[v] = visited[u] + 1;
            ans = max(ans, visited[v] - 1);
        }
    }

    return ans;
}

int main(){
    input();

    int dis = bfs();
    int cnt = 0, idx = 0;
    for (int i = 1; i <= n; i ++){ 
        if (visited[i] - 1 != dis) continue;
        if (idx == 0) idx = i;
        cnt ++;
    }

    cout << idx << ' ' << dis << ' ' << cnt;

}