#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000
using namespace std;

int s;
int dp[1001][1001];

void input(){
  fastio
  cin >> s;
  for (int i = 1; i <= s; ++ i){
    for (int j = 1; j <= s; ++ j){
      dp[i][j] = MAX;
    }
  }
}

void dfs(int scr, int clp, int cnt){
  if (scr > MAX || clp > MAX || cnt > 500) return;
  int nxt_cnt = cnt + 1;

  int nxt_scr = scr + clp;
  if (nxt_scr <= 1000){
    if (dp[nxt_scr][clp] > nxt_cnt){
      dp[nxt_scr][clp] = nxt_cnt;
      dfs(nxt_scr, clp, nxt_cnt);
    }
  }

  nxt_scr = scr - 1;
  if (nxt_scr > 0){
    if (dp[nxt_scr][clp] > nxt_cnt){
      dp[nxt_scr][clp] = nxt_cnt;
      dfs(nxt_scr, clp, nxt_cnt);
    }
  }

  int nxt_clp = scr;
  if (nxt_clp <= 1000){
    if (dp[scr][nxt_clp] > nxt_cnt){
      dp[scr][nxt_clp] = nxt_cnt;
      dfs(scr, nxt_clp, nxt_cnt);
    }
  }

}

void solve(){

  int ans = MAX;

  dp[1][1] = 1;
  dfs(1, 1, 1);
  // show();
  for (int i = 1; i <= s; ++ i){
    ans = min(ans, dp[s][i]);
  }
  cout << ans;
}

int main(){
  input();
  solve();
  return 0;
}