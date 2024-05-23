#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define black (-1)
#define rainbow 0
#define nothing 6
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
int map[21][21], visited[21][21];
typedef struct G{
    int idx, siz, rbw, i, j;
}group;
vector<group> groups;
bool cmp(group a, group b){
    if (a.siz == b.siz){
        if (a.rbw == b.rbw){
            if (a.i == b.i){
                return a.j > b.j;
            }
            return a.i > b.i;
        }
        return a.rbw > b.rbw;
    }
    return a.siz > b.siz;
}
int score, index;
queue<pair<int, int>> q;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
queue<int> dq;

void show(){
  cout << '\n';
  for (int i = 1; i <= N; ++ i){
    for (int j = 1; j <= N; ++ j){
      if (map[i][j] == black) cout << "X ";
      else if (map[i][j] == nothing) cout << "  ";
      else cout << map[i][j] << ' ';;
    }
    cout << '\n';
  }
}

void input(){
  fastio
  cin >> N >> M;
  for (int i = 1; i <= N; ++ i){
    for (int j = 1; j <= N; ++ j){
      cin >> map[i][j];
    }
  }
}

void make_group(int i, int j){
  int siz = 1, rbw = 0;

  visited[i][j] = ++ index;
  q.push({i, j});

  while (q.size()){
    int pi = q.front().first;
    int pj = q.front().second;
    q.pop();

    for (int d = 0; d < 4; ++ d){
      int ni = pi + di[d];
      int nj = pj + dj[d];

      if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
      if (map[ni][nj] == black || map[ni][nj] == nothing) continue;
      
      if (map[ni][nj] == rainbow){
        if (visited[ni][nj] == index) continue;
        rbw ++;
      }
      else if (visited[ni][nj]) continue;
      else if (map[ni][nj] != map[i][j]) continue;

      siz ++;
      visited[ni][nj] = index;
      q.push({ni, nj});
    }
  }

  if (siz > 1) groups.push_back({index, siz, rbw, i, j});
}

void clear_group(group g){
  score += g.siz * g.siz;
  // cout << "plus : " << g.siz * g.siz << '\n';

  visited[g.i][g.j] = 0;
  q.push({g.i, g.j});
  map[g.i][g.j] = nothing;

  while (q.size()){
    int pi = q.front().first;
    int pj = q.front().second;
    q.pop();

    for (int d = 0; d < 4; ++ d){
      int ni = pi + di[d];
      int nj = pj + dj[d];

      if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
      if (map[ni][nj] == black || map[ni][nj] == nothing) continue;

      if (map[ni][nj] == rainbow){
        if (visited[ni][nj] == 0) continue;
      }
      else if (visited[ni][nj] != g.idx) continue;

      visited[ni][nj] = 0;
      q.push({ni, nj});
      map[ni][nj] = nothing;
    }
  }

  for (int i = 1; i <= N; ++ i){
    for (int j = 1; j <= N; ++ j){
      visited[i][j] = 0;
    }
  }
}

void move(){
  int floor;

  for (int j = 1; j <= N; ++ j){
    floor = N + 1;
    for (int i = N; i >= 0; -- i){
      
      if (map[i][j] == nothing) continue;

      if (i == 0 || map[i][j] == black){
        for (int blank = floor - 1; blank > i; -- blank){
          if (dq.empty()) break;
          map[blank][j] = dq.front();
          dq.pop();
        }
        floor = i;
        continue;
      }
      
      dq.push(map[i][j]);
      map[i][j] = nothing;
    }
  }
}

void rotate(){
  int map0[N + 1][N + 1];

  for (int i = 1; i <= N; ++ i){
    for (int j = 1; j <= N; ++ j){
      map0[i][j] = map[i][j];
    }
  }
  // 11 = 15, 12 = 25
  for (int i = 1; i <= N; ++ i){
    for (int j = 1; j <= N; ++ j){
      map[i][j] = map0[j][N - i + 1];
    }
  }
}

void solve(){
  while (1){

    for (int i = 1; i <= N; ++ i){
      for (int j = 1; j <= N; ++ j){
        if (map[i][j] == black || map[i][j] == rainbow || map[i][j] == nothing || visited[i][j]) continue;
        make_group(i, j);
      }
    }

    if (groups.empty()) break;

    sort(groups.begin(), groups.end(), cmp);
    clear_group(groups.front());
    // show();

    move();
    // show();
    rotate();
    // show();
    move();
    // show();

    groups.clear();
  }

  cout << score;
}

int main(){
  input();
  solve();
  return 0;
}