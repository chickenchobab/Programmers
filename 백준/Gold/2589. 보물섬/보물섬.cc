#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
char map[51][51];
vector<pair<int, int>> lands;
typedef struct NODE{
  int i, j, dst;
}node;
queue<node> q;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
int ans;

void input(){
  fastio
  cin >> N >> M;
  string str;
  for (int i = 1; i <= N; ++ i){
    cin >> str;
    for (int j = 1; j <= M; ++ j){
      map[i][j] = str[j - 1];
      if (map[i][j] == 'L') lands.push_back({i, j});
    }
  }
}

void bfs(int i, int j){

  int visited[N + 1][M + 1] = {0,};

  visited[i][j] = 1;
  q.push({i, j, 0});

  while (q.size()){
    node f = q.front();
    q.pop();

    int i, j, dst;
    i = f.i, j = f.j, dst = f.dst;
    ans = max(ans, dst);

    for (int d = 0; d < 4; ++ d){
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
      if (map[ni][nj] == 'W' || visited[ni][nj] == 1) continue;
      
      visited[ni][nj] = 1;
      q.push({ni, nj, dst + 1});
    }
  }
}

void solve(){
  for (auto l : lands){
    bfs(l.first, l.second);
  }
  cout << ans;
}

int main(){
  input();
  solve();
  return 0;
}