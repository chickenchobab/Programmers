#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 100000000
using namespace std;

int N, M, S, D;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;
int dst[500];
vector<p> edges[500];
vector<int> path[500];
bool invalid[500][500];

void input(){
  fastio
}
bool input0(){
  cin >> N >> M;
  if (!N && !M) return 0;
  cin >> S >> D;
  int U, V, P;
  while (M --){
    cin >> U >> V >> P;
    edges[U].push_back({P, V});
  }
  return 1;
}

void find_path(){
  for (int i = 0; i < N; ++ i)
    dst[i] = INF;

  pq.push({0, S});
  dst[S] = 0;

  while (pq.size()){
    p node = pq.top();
    int cur = node.second;
    pq.pop();

    if (dst[cur] < node.first) continue;

    for (p node : edges[cur]){
      int nxt = node.second;
      int wgh = node.first;
      if (invalid[cur][nxt]) continue;

      if (dst[nxt] > dst[cur] + wgh){
        path[nxt].clear();
        path[nxt].push_back(cur);
        dst[nxt] = dst[cur] + wgh;
        pq.push({dst[nxt], nxt});
      }
      else if (dst[nxt] == dst[cur] + wgh){
        path[nxt].push_back(cur);
      }
    }
  }
}

void remove_edge(int cur){

  for (int prv : path[cur]){
    if (invalid[prv][cur]) continue;
    invalid[prv][cur] = 1;
    remove_edge(prv);
  }
}

void reset(){
  for (int i = 0; i < N; ++ i){
    path[i].clear();
    edges[i].clear();
  }
  for (int i = 0; i < N; ++ i)
    for (int j = 0; j < N; ++ j)
      invalid[i][j] = 0;
}

void solve(){
  while (input0()){
    
    find_path();
    remove_edge(D);
    find_path();

    if (dst[D] == INF) cout << -1;
    else cout << dst[D];
    cout << '\n';

    reset();
  }
}

int main(){
  input();
  solve();
  return 0;
}