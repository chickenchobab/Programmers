#include <iostream>
#include <algorithm>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

deque<int> pos[3];

void input(){
  fastio
}

void solve(){
  int removeCnt = 0;
  
  char ch;
  for (int i = 0; ; ++i){
    ch = cin.get();
    if (ch == '\n') break;
    pos[ch - 'A'].push_back(i);
  }

  int emptyCnt;
  while (pos[1].size()){
    emptyCnt = 0;
    
    if (pos[0].empty()) ++emptyCnt;
    else if (pos[0].back() < pos[1].back()){
      pos[0].pop_back();
      pos[1].pop_back();
      ++removeCnt;
    }
    else pos[0].pop_back();

    if (pos[1].empty()) break;

    if (pos[2].empty()) ++emptyCnt;
    else if (pos[2].front() > pos[1].front()){
      pos[2].pop_front();
      pos[1].pop_front();
      ++removeCnt;
    }
    else pos[2].pop_front();

    if (emptyCnt == 2) break;
  }
  
  cout << removeCnt;
}

int main(){
  input();
  solve();
  return 0;
}