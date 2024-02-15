#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, m;
vector<int> edge[50005];
int level[50005], parent[50005];

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
        parent[nxt] = cur;
        check_level(nxt);
    }
}

int lca(int a, int b){

    if (level[a] < level[b]) swap(a, b);

    while (level[a] != level[b]) a = parent[a];

    while (a != b){
        a = parent[a];
        b = parent[b];
    }

    return a;
}


int main(){
    input();

    level[1] = 1;
    check_level(1);

    cin >> m;
    int a, b;
    while (m --){
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}


