#include <iostream>
#include <vector>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, m;
int max_lev;
vector<int> edge[100001];
int level[100001];
vector<int> parent[100001];

void input(){
    fastio
    int a, b;
    cin >> n;
    for (int i = 1; i <= n - 1; i ++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    max_lev = (int)floor(log2(n + 1));
    for (int i = 0; i <= n; i ++){
        parent[i].resize(max_lev + 1, 0);
    }
}

void set_tree(int cur){

    for (int nxt : edge[cur]){
        if (level[nxt]) continue;

        level[nxt] = level[cur] + 1;
        parent[nxt][0] = cur;

        for (int i = 1; i <= max_lev; i ++)
            parent[nxt][i] = parent[parent[nxt][i - 1]][i - 1];
        
        set_tree(nxt);
    }
}

int lca(int a, int b){

    if (a == 1 || b == 1) return 1;

    if (level[a] < level[b]) swap(a, b);

    if (level[a] != level[b]) {
        for (int i = max_lev; i >= 0; i --){
            if (level[parent[a][i]] >= level[b])
            a = parent[a][i];
        }
    }

    int ret = a;
    if (a != b){
        for (int i = max_lev; i >= 0; i --){
            if (parent[a][i] != parent[b][i]){
                a = parent[a][i];
                b = parent[b][i];
            }
            ret = parent[a][i];
        }
    }

    return ret;
}


int main(){
    input();

    level[1] = 1;
    set_tree(1);

    cin >> m;
    int a, b;
    while (m --){
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}


