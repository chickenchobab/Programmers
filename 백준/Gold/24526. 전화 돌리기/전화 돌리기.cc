#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
vector<int> edge[100001];

int visit_count, cycle_count;
// int visited[100001];  // 1:in stack, 2:out of stack, 3:out of stack(cycle factor)
int indegree[100001];

void input(){
    fastio
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i ++){
        cin >> u >> v;
        edge[v].push_back(u);
        indegree[u] ++;
    }
}

// bool dfs(int cur){

//     visited[cur] = 1;
//     visit_count ++;

//     bool cycle = 0;
    
//     for (int nxt : edge[cur]){
//         if (visited[nxt]){
//             if (visited[nxt] != 2) {
//                 // cout << "cycle : " << cur << ' ' << nxt << '\n';
//                 cycle = 1;
//             }
//             continue;
//         }
//         if (dfs(nxt)) cycle = 1;
//     }

//     visited[cur] = 2;
//     if (cycle) {
//         visited[cur] ++;
//         cycle_count ++;
//     }
//     return cycle;
// }

void toposort(){
    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= n; i ++){
        if (indegree[i] == 0) q.push(i);
    }

    for (int i = 1; i <= n; i ++){
        if (!q.size()) break;
        int cur = q.front();
        q.pop();
        ans ++;
        for (int nxt : edge[cur]){
            if (-- indegree[nxt] == 0) q.push(nxt);
        }
    }
    cout << ans;
    return;
}

// void solve1(){
//     for (int i = 1; i <= n; i ++){
//         if (visited[i]) continue;
//         dfs(i);
//     }
//     cout << visit_count - cycle_count;
// }

void solve2(){
    toposort();
}

int main(){
    input();
    // solve1();
    solve2();
    
    return 0;
}