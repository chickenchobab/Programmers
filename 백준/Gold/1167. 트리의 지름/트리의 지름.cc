#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int V;
typedef pair<int, int> p;
vector<p> edges[100001];
int ans;

void input(){
  fastio
  cin >> V;
  int a, b, w;
  for (int i = 1; i <= V; ++ i){
    cin >> a;
    while (1){
      cin >> b;
      if (b == -1) break;
      cin >> w;
      edges[a].push_back({w, b});
    }
  }
}

int dfs(int prv, int cur, int dst){
  int fst, scn;
  fst = 0, scn = 0;

  for (auto e : edges[cur]){
    int nxt = e.second;
    int wgh = e.first;
    if (prv == nxt) continue;

    int tmp = dfs(cur, nxt, dst + wgh) + wgh;
    if (tmp >= fst){
      scn = fst;
      fst = tmp;
    }
    else if (tmp >= scn){
      scn = tmp;
    }
  }
  ans = max(ans, fst + scn);
  return fst;
}

void solve(){
  dfs(0, 1, 0);
  cout << ans;
}

int main(){
  input();
  solve();
  return 0;
}