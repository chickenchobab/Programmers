#include <iostream>
#include <algorithm>
#include <unordered_map>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000000000
using namespace std;

int t, n, m;
int a[1001], b[1001];
unordered_map<int, long long> mp;

void input(){
  fastio
  cin >> t;
  int num;
  
  cin >> n;
  for (int i = 1; i <= n; ++ i) {
    cin >> num;
    a[i] = a[i - 1] + num;
  }
  cin >> m;
  for (int i = 1; i <= m; ++ i) {
    cin >> num;
    b[i] = b[i - 1] + num;
  }
}

void solve(){

  long long cnt = 0;

  for (int i = 1; i <= n; ++ i){
    for (int j = i; j <= n; ++ j){
      int sum = a[j] - a[i - 1];
      if (mp.count(sum)) mp[sum] ++;
      else mp[sum] = 1;
    }
  }

  for (int i = 1; i <= m; ++ i){
    for (int j = i; j <= m; ++ j){
      int sum = b[j] - b[i - 1];
      if (mp.count(t - sum)) cnt += mp[t - sum];
    }
  }
  cout << cnt;
}

int main(){
  input();
  solve();
  return 0;
}