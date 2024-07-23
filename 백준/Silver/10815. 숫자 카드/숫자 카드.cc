#include <iostream>
#include <algorithm>
#include <unordered_set>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
unordered_set<int> numCards;

void input(){
  fastio
  cin >> N;
  int num;
  while (N--){
    cin >> num;
    numCards.insert(num);
  }
}

void solve(){
  cin >> M;
  int num;
  while (M--){
    cin >> num;
    cout << (bool)numCards.count(num) << ' ';
  }
}

int main(){
  input();
  solve();
  return 0;
}