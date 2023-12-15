#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 100000

using namespace std;

typedef pair<pair<int, int>, int> p;
int n, m, x, a, b, t;
vector<p> edge[1001];
priority_queue<p, vector<p>, greater<p>> pq;
int d0[1001], d1[1001];

int *arr(int num){
    if (num == 0) return d0;
    return d1;
}

void dijkstra(){

    for (int i=1; i<=n; i++) d0[i] = d1[i] = INF;
    d0[x] = d1[x] = 0;
    pq.push({{0, x}, 0});
    pq.push({{0, x}, 1});

    while(pq.size()){
        p u = pq.top();
        pq.pop();

        if (arr(u.second)[u.first.second] < u.first.first) continue;
        for (p v : edge[u.first.second]){
            if (v.second != u.second) continue;
            int uv = v.first.first;
            int *d = arr(v.second);
            if (d[v.first.second] < uv + d[u.first.second]) continue;
            d[v.first.second] = uv + d[u.first.second];
            pq.push({{d[v.first.second], v.first.second}, v.second});
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> x;

    for (int i=1; i<=m; i++){
        cin >> a >> b >> t;
        edge[a].push_back({{t, b}, 0});
        edge[b].push_back({{t, a}, 1});
    }

    dijkstra();
    
    int ans = 0;
    for (int i=1; i<=n; i++){
        ans = max(ans, d0[i] + d1[i]);
    }

    cout << ans;

}
