#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, l;
int cnt;
vector<int> edge[10001];
int len[10001], visited[10001];

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i ++){
        cin >> a >> b;
        edge[b].push_back(a);
    }
}

// int dfs(int cur){
    
//     int sum = 0;
//     for (int nxt : edge[cur]){
//         if (visited[nxt]) continue;
//         visited[nxt] = 1;
//         sum = max(sum, dfs(nxt));
//         visited[nxt] = 0;
//     }
//     return sum + 1;
// }

void dfs(int cur){
    visited[cur] = 1;
    for (int nxt : edge[cur]){
        if (visited[nxt]) continue;
        dfs(nxt);
        cnt ++;
    }
}

int main(){
    input();
    // for (int i = 1; i <= n; i ++){
    //     visited[i] = 1;
    //     l = max(l, dfs(i));
    //     visited[i] = 0;
    // }

    for (int i = 1; i <= n; i ++){
        cnt = 0;
        dfs(i);
        len[i] = cnt;
        l = max(l, cnt);
        fill(visited + 1, visited + n + 1, 0);
    }
    for (int i = 1; i <= n; i ++){
        if (len[i] == l) cout << i << ' ';
    }
}