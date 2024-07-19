#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int arr[100001];

void input(){
  fastio
  cin >> n;
}

void solve(){

  string ans = "";
  stack<int> st;
  int num = 1, tmp;

  for (int i = 1; i <= n; ++i){
    cin >> tmp;
    while (st.empty() || st.top() < tmp) {
      st.push(num++);
      ans += "+\n";
    }
    if (st.top() == tmp){
      st.pop();
      ans += "-\n";
    }
  }

  if (st.empty()) cout << ans;
  else cout << "NO";
}

int main(){
  input();
  solve();
  return 0;
}