#include <iostream>
#include <vector>
using namespace std;

int t;
int n;
int match, visit;
int edge[100001], visited[100001];

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
}

void input(){

    cin >> n;
    match = visit = 0;
    for (int i = 1; i <= n; i ++){
        cin >> edge[i];
        visited[i] = 0;
    }
}

void dfs(int node, int st, int cur){
    if (visited[node] >= st){
        match += (cur - visited[node]);
        return;
    }
    if (visited[node]) return;
    visited[node] = ++ visit;
    dfs(edge[node], st, cur + 1);
}

int main(){
    init();
    while (t --){
        input();
        for (int i = 1; i <= n; i ++){
            if (visited[i]) continue;
            dfs(i, visit + 1, visit + 1);
        }
        cout << n - match << '\n';
    }
}