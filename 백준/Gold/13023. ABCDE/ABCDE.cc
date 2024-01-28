#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int visited[2000];
vector<int> edge[2000];
int flag;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i ++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}

void dfs(int cur, int len){
    
    if (len >= 5) {
        flag = 1;
        return;
    }
    for (int nxt : edge[cur]){
        if (visited[nxt]) continue;
        visited[nxt] = 1;
        dfs(nxt, len + 1);
        visited[nxt] = 0;
    }
}

int main(){
    input();
    for (int i = 0; i < n && flag == 0; i ++){
        fill(visited, visited + n, 0);
        visited[i] = 1;
        dfs(i, 1);
    }
    cout << flag;
}