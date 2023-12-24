#include <iostream>
#include <vector>

using namespace std; 

int n;
vector<int> g[3 * 3 * 3];
int visited[3 * 3 * 3];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    char a, b, c;
    for (int i=1; i<=n; i++){
        cin >> a >> b >> c;
        b = b == '.'? '.' : b - 'A';
        c = c == '.'? '.' : c - 'A';
        g[a - 'A'].push_back(b);
        g[a - 'A'].push_back(c);
    }
}

void reset(){
    for (int i=1; i<=n; i++) 
        visited[i] = 0;
}

void dfs(int u, int order){

    if (u == '.') return;
    visited[u] = 1;

    if (order == 1) cout << (char)(u + 'A');
    if (visited[g[u][0]] == 0)
        dfs(g[u][0], order);
    if (order == 2) cout << (char)(u + 'A');
    if (visited[g[u][1]] == 0)
        dfs(g[u][1], order);
    if (order == 3) cout << (char)(u + 'A');
}

int main(){

    input();
    dfs(0, 1); cout << '\n';
    reset();
    dfs(0, 2); cout << '\n';
    reset();
    dfs(0, 3); cout << '\n';
    return 0;
}