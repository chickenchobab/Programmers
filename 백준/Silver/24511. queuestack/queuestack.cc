#include <iostream>
#include <algorithm>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
bool isStack[100000];
deque<int> dq;

void input(){
  fastio
  cin >> N;
  
  for (int i = 0; i < N; ++i){
    cin >> isStack[i];
  }

  int num;
  for (int i = 0; i < N; ++i){
    cin >> num;
    if (!isStack[i]) dq.push_back(num);
  }
}

void solve(){
  cin >> M;
  int num;
  while (M--){
    cin >> num;
    if (dq.size()){
      dq.push_front(num);
      num = dq.back();
      dq.pop_back();
    }
    cout << num << ' ';
  }
}

int main(){
  input();
  solve();
  return 0;
}