#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
bool visited[101], cycled[101];
vector<int> edge[101];
int cnt;

void input(){
    fastio
    cin >> n;
    int num;
    for (int i = 1; i <= n; i ++) {
        cin >> num;
        edge[i].push_back(num);
    }
}

bool dfs(int start, int cur){

    visited[cur] = 1;

    for (int nxt : edge[cur]){
        if (nxt == start) return true;
        if (visited[nxt]) continue;
        return dfs(start, nxt);
    }
    return false;
}

void reset(){
    for (int i = 1; i <= n; i ++) visited[i] = 0;
}

void solve(){
    for (int i = 1; i <= n; i ++){
        if (dfs(i, i)) {
            cycled[i] = 1;
            cnt ++;
        }
        reset();
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; i ++){
        if (cycled[i]) cout << i << '\n';
    }
}

int main(){
    input();
    solve();
    return 0;
}