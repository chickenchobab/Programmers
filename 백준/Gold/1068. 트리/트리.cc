#include <iostream>
#include <vector>

using namespace std;

int n, ans, root, del;
vector<int> g[50];
int visited[50];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n; 
    int tmp;
    for (int i = 0; i < n; i ++){
        cin >> tmp;
        if (tmp == -1) {
            root = i;
            continue;
        }
        g[tmp].push_back(i);
    }
    cin >> del;
}

void dfs(int u){
    int cnt = 0;
    visited[u] = 1;
    for (int v : g[u]){
        if (visited[v]) continue;
        if (v == del) continue;
        cnt ++;
        dfs(v);
    }
    if (cnt == 0) ans ++;
}

int main(){
    input();
    if (root != del) dfs(root);
    cout << ans;
}