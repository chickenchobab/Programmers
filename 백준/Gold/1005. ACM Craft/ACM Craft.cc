#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int T;
int N, K, D[1001];
int X, Y, W;
vector<int> edges[1001];
int ind[1001];
queue<int> q;
int dp[1001];

void input(){
  fastio
  cin >> T;
}
void input0(){
  cin >> N >> K;
  for (int i = 1; i <= N; ++ i){
    cin >> D[i];
  }
  for (int i = 1; i <= K; ++ i){
    cin >> X >> Y;
    edges[X].push_back(Y);
    ind[Y] ++;
  }
  cin >> W;
}

void reset(){
  for (int i = 1; i <= N; ++ i){
    edges[i].clear();
    ind[i] = 0;
    dp[i] = 0;
  }
}

void toposort(){
  for (int i = 1; i <= N; ++ i){
    if (ind[i] == 0){
      dp[i] = D[i];
      q.push(i);
    }
  }

  while (q.size()){
    int cur = q.front();
    // cout << cur << ' ';
    q.pop();

    for (int nxt : edges[cur]){
      if (-- ind[nxt] == 0) q.push(nxt);
      dp[nxt] = max(dp[nxt], dp[cur] + D[nxt]);
    }
  }
}

void solve(){
  while (T --){
    input0();
    toposort();
    cout << dp[W] << '\n';
    reset();
  }
}

int main(){
  input();
  solve();
  return 0;
}