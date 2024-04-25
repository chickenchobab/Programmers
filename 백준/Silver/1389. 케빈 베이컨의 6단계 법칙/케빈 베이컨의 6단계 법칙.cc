#include <iostream>
#include <algorithm>
#include <vector>
#define INF 10000
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int graph[101][101];

void input(){
    fastio
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            graph[i][j] = INF;
        }
    }
    int a, b;
    for (int i = 0; i < m; i ++){
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }
}

void floyd_warshall(){  
    for (int s = 1; s <= n; s ++){
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= n; j ++){
                if (i == s || j == s) continue;
                graph[i][j] = min(graph[i][j], graph[i][s] + graph[s][j]);
            }
        }
    }
}

void solve(){
    int wincnt, winnum;
    wincnt = INF;

    floyd_warshall();

    for (int i = 1; i <= n; i ++){
        int cnt = 0;
        for (int j = 1; j <= n; j ++){
            if (i == j) continue;
            cnt += graph[i][j];
        }
        if (cnt < wincnt){
            wincnt = cnt;
            winnum = i;
        }
    }

    cout << winnum;
}

int main(){
    input();
    solve();
    return 0;
}