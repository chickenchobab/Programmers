#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000000
using namespace std;

typedef pair<int, int> p;
int n, m, a, b, c, x, y;
vector<p> edge[1001];
int d[1001];

int dijkstra(){
    
    priority_queue<p, vector<p>, greater<p>> pq;
    d[x] = 0;
    pq.push({0, x});

    while(pq.size()){
        p u = pq.top();
        pq.pop();
        if (d[u.second] < u.first) continue;
        for (p v: edge[u.second]){
            int uv = v.first;
            if (d[v.second] > uv + u.first){
                d[v.second] = uv + u.first;
                pq.push({d[v.second], v.second});
            }
        }
    }

    return d[y];
}

int main(){

    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i=1; i<=n; i++){
        d[i] = MAX;
    }
    for (int i=1; i<=m; i++){
        cin >> a >> b >> c;
        edge[a].push_back({c, b});
    }
    cin >> x >> y;
    cout << dijkstra();
    return 0;
}