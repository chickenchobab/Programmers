#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, K;

void input(){
  fastio
  cin >> N >> K;
}

void solve(){
  queue<int> q;
  for (int i = 1; i <= N; ++i)
    q.push(i);

  cout << "<";
  while (q.size()){
    for (int i = 1; i < K; ++i){
      q.push(q.front());
      q.pop();
    }
    cout << q.front();
    q.pop();
    if (q.size()) cout << ", ";
  }
  cout << ">";
}

int main(){
  input();
  solve();
  return 0;
}