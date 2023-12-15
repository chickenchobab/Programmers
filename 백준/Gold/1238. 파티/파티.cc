#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 100000

using namespace std;

typedef pair<int, int> p;
int n, m, x, a, b, t;
vector<p> e1[1001], e2[1001];
priority_queue<p, vector<p>, greater<p>> pq;
int d1[1001], d2[1001];

int *arr(int num){
    if (num == 1) return d1;
    return d2;
}
vector<p> * vec(int num){
    if (num == 1) return e1;
    return e2;
}

void dijkstra(int num){

    int *d = arr(num);
    vector<p> * e = vec(num);

    for (int i=1; i<=n; i++) d[i] = INF;
    d[x] = 0;
    pq.push({0, x});

    while(pq.size()){
        p u = pq.top();
        pq.pop();
        if (d[u.second] < u.first) continue;
        for (p v : e[u.second]){
            int uv = v.first;
            if (d[v.second] < d[u.second] + uv) continue;
            d[v.second] = d[u.second] + uv;
            pq.push({d[v.second], v.second});
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
        e1[a].push_back({t, b});
        e2[b].push_back({t, a});
    }

    dijkstra(1); dijkstra(2);

    int ans = 0;
    for (int i=1; i<=n; i++){
        ans = max(ans, d1[i] + d2[i]);
    }

    cout << ans;
}
