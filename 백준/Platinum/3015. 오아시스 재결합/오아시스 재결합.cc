#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int N;
stack<pair<int, int>> st;

void input(){
  fastio
  cin >> N;
}

void solve(){
  int tmp;
  long long ans = 0;
  
  while (N --){
    cin >> tmp;
    while (st.size() && st.top().first < tmp){
      ans ++;
      st.pop();
    }
    if (st.size()) {
      if (st.top().first == tmp) {
        ans += (st.top().second + (st.size() > st.top().second));
        st.push({tmp, st.top().second + 1});
      }
      else {
        ans += 1;
        st.push({tmp, 1});
      }
    }
    else st.push({tmp, 1});
  }
  cout << ans;
}

int main(){
  input();
  solve();
  return 0;
}