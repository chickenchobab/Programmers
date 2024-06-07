#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int T, N, X, Y;
vector<int> edges[10001];
bool visited[10001];
int ans;

void input(){
  fastio
  cin >> T;
}
void input0(){
  cin >> N;
  for (int i = 1; i <= N; ++ i){
    edges[i].clear();
    visited[i] = 0;
  }
  int a, b;
  for (int i = 1; i < N; ++ i){
    cin >> a >> b;
    edges[b].push_back(a); // to start from a child
  }
  cin >> X >> Y;
}

void dfs(int cur){
  visited[cur] = 1;
  for (int nxt : edges[cur]){
    if (visited[nxt]) {
      ans = nxt;
      return;
    }
    dfs(nxt);
  }
}

void solve(){
  while (T --){
    input0();
    dfs(X); dfs(Y);
    cout << ans << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}