#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 200000000
using namespace std;
int N, E;
typedef struct EDGE{
  int wgh, nod;
}edge;
struct cmp{
  bool operator()(edge &a, edge &b){
    return a.wgh > b.wgh;
  }
};
priority_queue<edge, vector<edge>, cmp> pq;
vector<edge> edges[808];
int u, v;
int dus, due, duv, dvs, dve; // s = 1, e = n

void input(){
  fastio
  cin >> N >> E;
  int a, b, c;
  for (int i = 1; i <= E; ++ i){
    cin >> a >> b >> c;
    edges[a].push_back({c, b});
    edges[b].push_back({c, a});
  }
  cin >> u >> v;
}

void dijkstra(int s){
  int dst[N + 1];

  for (int i = 1; i <= N; ++ i) dst[i] = MAX;
  dst[s] = 0;
  pq.push({0, s});

  while (pq.size()){
    int cur = pq.top().nod;
    int wgh = pq.top().wgh;
    pq.pop();

    if (dst[cur] < wgh) continue;

    for (auto tmp : edges[cur]){
      int nxt = tmp.nod;
      int wgh = tmp.wgh;
      if (dst[nxt] > dst[cur] + wgh){
        dst[nxt] = dst[cur] + wgh;
        pq.push({dst[nxt], nxt});
      }
    }
  }

  if (s == u) {
    dus = dst[1]; due = dst[N]; duv = dst[v];
  }
  else if (s == v){
    dvs = dst[1], dve = dst[N];
  }
}

void solve(){
  int ans;
  dijkstra(u);
  dijkstra(v);
  ans = min(dus + duv + dve, dvs + duv + due);
  if (ans >= MAX) ans = -1;
  cout << ans;
}

int main(){
  input();
  solve();
  return 0;
}