#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 100000

using namespace std;

typedef pair<int, int> p;
int n, m, x, a, b, t;
vector<p> edge[1001];

int dijkstra(int u, int v){
    priority_queue<p, vector<p>, greater<p>> pq;
    int d[1001];
    for (int i=1; i<=n; i++) d[i] = INF;
    d[u] = 0;
    pq.push({0, u});
    while(pq.size()){
        p i = pq.top();
        pq.pop();
        if (d[i.second] < i.first) continue;
        for (p j : edge[i.second]){
            int ij = j.first;
            if (d[j.second] > d[i.second] + ij){
                d[j.second] = d[i.second] + ij;
                pq.push(make_pair(d[j.second], j.second));
                //cout << j.second << ' ';
            }
        }
    }
    return d[v];
}

int main(){
    
    cin >> n >> m >> x;
    for (int i=1; i<=m; i++){
        cin >> a >> b >> t;
        edge[a].push_back({t,b});
    }

    int ans = 0;
    for (int i=1; i<=n; i++){
        ans = max(ans, dijkstra(i, x) + dijkstra(x, i));
    }

    cout << ans;
}
