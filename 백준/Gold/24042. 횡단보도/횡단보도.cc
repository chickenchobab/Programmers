#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 111111111111
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef unsigned long long ll;
typedef pair<ll, int> p;
int n, m;
vector<p> edges[100001];

ll dist[100001];
priority_queue<p, vector<p>, greater<p>> pq;

void input(){
    fastio
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i ++){
        cin >> a >> b;
        edges[a].push_back({i, b});
        edges[b].push_back({i, a});
    }
}


void dijkstra(){

    for (int i = 2; i <= n; i ++) dist[i] = INF;
    pq.push({0, 1});

    while (pq.size()) {
        int cur = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if (dist[cur] < d) continue;

        for (auto edge : edges[cur]){
            int nxt = edge.second;
            int c = edge.first;
            ll t = d % m > c ? c + m - d % m : c - d % m;
            if (dist[nxt] > d + (t + 1)){
                dist[nxt] = d + (t + 1);
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main(){
    input();
    dijkstra();
    cout << dist[n];
    return 0;
}