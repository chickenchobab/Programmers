#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 10000
using namespace std;

int T, H, W;
char map[102][102];
typedef pair<int, int> p;
vector<p> people;
int cnt[3][102][102];
deque<p> dq;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void input(){
  fastio
  cin >> T;
}
void input0(){
  cin >> H >> W;
  people.clear();
  people.push_back({0, 0});
  string str;
  for (int i = 1; i <= H; ++ i){
    cin >> str;
    for (int j = 1; j <= W; ++ j){
      map[i][j] = str[j - 1];
      if (map[i][j] == '$') people.push_back({i, j});
    }
  }

  H ++; W ++; 
  for (int i = 0; i <= H; ++ i)
    map[i][0] = map[i][W] = '.';
  for (int j = 1; j <= W; ++ j)
    map[0][j] = map[H][j] = '.';

  for (int k = 0; k < 3; ++ k){
    for (int i = 0; i <= H; ++ i){
      for (int j = 0; j <= W; ++ j){
        cnt[k][i][j] = -1;
      }
    }
  }
}

void bfs(int idx){

  int i = people[idx].first;
  int j = people[idx].second;
  dq.push_back({i, j});
  cnt[idx][i][j] = 0;

  while (dq.size()){
    int i = dq.front().first;
    int j = dq.front().second;
    dq.pop_front();

    for (int d = 0; d < 4; ++ d){
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 0 || ni > H || nj < 0 || nj > W) continue;
      if (map[ni][nj] == '*') continue;
      if (cnt[idx][ni][nj] != -1) continue;

      if (map[ni][nj] == '#'){
        cnt[idx][ni][nj] = cnt[idx][i][j] + 1;
        dq.push_back({ni, nj});
      }
      else {
        cnt[idx][ni][nj] = cnt[idx][i][j];
        dq.push_front({ni, nj});
      }
    }
  }
}

void solve(){
  int ans, sum;
  while (T --){
    input0();
    bfs(0); bfs(1); bfs(2);

    ans = INF;
    for (int i = 0; i <= H; ++ i){
      for (int j = 0; j <= W; ++ j){
        if (map[i][j] == '*') continue;
        if (cnt[0][i][j] == -1 || cnt[1][i][j] == -1 || cnt[2][i][j] == -1) continue;
        sum = cnt[0][i][j] + cnt[1][i][j] + cnt[2][i][j];
        ans = min(ans, sum - 2 * (map[i][j] == '#'));
      }
    }
    cout << ans << '\n';
    
  }

}

int main(){
  input();
  solve();
  return 0;
}