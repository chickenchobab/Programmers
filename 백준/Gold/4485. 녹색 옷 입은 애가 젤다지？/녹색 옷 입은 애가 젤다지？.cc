#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 50000
using namespace std;
int N;
int map[126][126];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
typedef struct EDGE{
  int wgh, i, j;
}edge;
struct cmp{ // greater 
  bool operator()(edge &a, edge &b){
    return a.wgh > b.wgh;
  }
};
priority_queue<edge, vector<edge>, cmp> pq;

void input(){
  fastio
}

bool input0(){
  cin >> N;
  if (N == 0) return 0;

  for (int i = 1; i <= N; ++ i){
    for (int j = 1; j <= N; ++ j){
      cin >> map[i][j];
    }
  }
  return 1;
}

int dijkstra(){

  int dst[N + 1][N + 1];
  for (int i = 1; i <= N; ++ i){
    for (int j = 1; j <= N; ++ j){
      dst[i][j] = INF;
    }
  }

  dst[1][1] = map[1][1];
  pq.push({map[1][1], 1, 1});

  while (pq.size()){
    edge cur = pq.top();
    pq.pop();

    int i = cur.i, j = cur.j;
    if (dst[i][j] < cur.wgh) continue;

    for (int d = 0; d < 4; ++ d){
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
      if (dst[ni][nj] > dst[i][j] + map[ni][nj]){
        dst[ni][nj] = dst[i][j] + map[ni][nj];
        pq.push({dst[ni][nj], ni, nj});
      }
    }
  }

  return dst[N][N];
}

void solve(){
  int turn = 0;
  while (1){
    if (input0() == 0) return;
    turn ++;
    cout << "Problem " << turn << ": ";
    cout << dijkstra() << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}