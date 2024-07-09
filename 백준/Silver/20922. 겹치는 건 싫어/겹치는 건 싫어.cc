#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, K;
int arr[200002]; 
int cnt[100001];

void input(){
  fastio
  cin >> N >> K;
}

void solve(){
  int s = 0, e = 0, ans = 1;
  for (e = 0; e < N; ++ e){
    cin >> arr[e];
    cnt[arr[e]] ++;
    while (cnt[arr[e]] > K){
      cnt[arr[s]] --;
      s ++;
    }
    ans = max(ans, e - s + 1);
  }
  cout << ans;
}

int main(){
  input();
  solve();
  return 0;
}