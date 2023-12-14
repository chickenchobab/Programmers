#include <iostream>
#include <algorithm>
#define INF 100000

using namespace std;

typedef pair<int, int> p;
int n, m, x, a, b, t;
int graph[1001][1001];

int floyd_warshall(){
    for (int s=1; s<=n; s++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                //if (graph[i][s] == INF || graph[s][j] == INF) continue;
                graph[i][j] = min(graph[i][j], graph[i][s] + graph[s][j]);
            }
        }
    }

    int ans = 0;
    for (int i=1; i<=n; i++){
        if (i == x) graph[i][i] = 0;
        else graph[i][i] = graph[i][x] + graph[x][i];
        ans = max(ans, graph[i][i]);
    }

    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> x;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            graph[i][j] = INF;
        }
    }

    for (int i=1; i<=m; i++){
        cin >> a >> b >> t;
        graph[a][b] = t;
    }

    cout << floyd_warshall();

}
