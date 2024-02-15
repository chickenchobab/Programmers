#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, m;
vector<int> edge[50005];
int level[50005], visited[50005];

void input(){
    fastio
    int a, b;
    cin >> n;
    for (int i = 1; i <= n - 1; i ++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}

void check_level(int cur){

    for (int nxt : edge[cur]){
        if (level[nxt]) continue;
        level[nxt] = level[cur] + 1;
        check_level(nxt);
    }
}

int dfs(int cur){

    if (visited[cur]) return cur;
    else visited[cur] = 1;

    for (int nxt : edge[cur]){
        if (level[nxt] > level[cur]) continue;
        return dfs(nxt);
    }

    return cur;
}


int main(){
    input();

    level[1] = 1;
    check_level(1);

    cin >> m;
    int a, b;
    int ans1, ans2;
    while (m --){
        cin >> a >> b;
        for (int i = 1; i <= n; i ++) visited[i] = 0;
        
        ans1 = dfs(a);
        ans2 = dfs(b);
        level[ans1] > level[ans2] ? cout << ans1 : cout << ans2;
        cout << '\n';
    }

    return 0;
}


