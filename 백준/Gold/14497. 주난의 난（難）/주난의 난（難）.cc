#include <iostream>
#include <algorithm>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
int x1, y1, x2, y2;
char map[301][301];
int visited[301][301];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
deque<pair<int, int>> dq;

void input(){
  fastio
  cin >> N >> M;
  cin >> x1 >> y1 >> x2 >> y2;
  string str;
  for (int i = 1; i <= N; ++ i){
    cin >> str;
    for (int j = 1; j <= M; ++ j){
      map[i][j] = str[j - 1];
    }
  }
}

void bfs(){
  dq.push_back({x1, y1});
  visited[x1][y1] = 1;

  while (dq.size()){
    int i = dq.front().first;
    int j = dq.front().second;
    dq.pop_front();

    for (int d = 0; d < 4; ++ d){
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
      if (visited[ni][nj]) continue;

      if (map[ni][nj] == '1'){
        dq.push_back({ni, nj});
        visited[ni][nj] = visited[i][j] + 1;
      }
      else {
        dq.push_front({ni, nj});
        visited[ni][nj] = visited[i][j];
      }
    }
  }
}

void show(){
  for (int i = 1; i <= N; ++ i){
    for (int j = 1; j <= M; ++ j){
      cout << visited[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

void solve(){
  // show();
  bfs();
  // show();
  cout << visited[x2][y2];
}

int main(){
  input();
  solve();
  return 0;
}