#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int T;
string str;

void input(){
  fastio
  cin >> T;
}

void query(){
  int i, j, len;
  len = str.length(); 

  for (i = len - 2; i >= 0 && str[i] >= str[i + 1]; i --);
  if (i == -1) return;
  for (j = len - 1; j > i && str[i] >= str[j]; j --);

  swap(str[i], str[j]);
  sort(str.begin() + i + 1, str.end());
}

void solve(){
  while (T --){
    cin >> str;
    query();
    cout << str << '\n';
  }
}

int main(){
    input();
    solve();
    return 0;
}