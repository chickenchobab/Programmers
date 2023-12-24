#include <iostream>
#include <vector>

using namespace std;

int n, m, t, cnt;
vector<int> g[505];
int visited[505];

bool input(){
    cin >> n >> m;
    if (!n && !m) return false;

    int a, b;
    for (int i = 1; i <= m; i ++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    return true;
}

void reset(){  
    cnt = 0;
    for (int i = 1; i <= n; i ++){
        g[i].clear();
        visited[i] = 0;
    }
    t ++;
}

bool dfs(int v, int u){
    visited[v] = 1;

    for (int w : g[v]){
        if (w == u) continue;
        if (visited[w]) return false;
        if (!dfs(w, v)) return false;
    }

    return true;
}

void check(){
    for (int i = 1; i <= n; i ++){
        if (visited[i]) continue;
        if (dfs(i, 0)) cnt ++;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    t = 1;

    while(1){

        if (!input()) break;

        check();

        cout << "Case " << t << ": ";
        if (cnt == 0) cout << "No trees.";
        else if (cnt == 1) cout << "There is one tree.";
        else cout << "A forest of " << cnt << " trees.";
        cout << '\n';

        reset();
    }

    return 0;
}