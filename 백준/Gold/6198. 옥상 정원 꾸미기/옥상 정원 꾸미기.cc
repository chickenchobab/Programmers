#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int h[80008];

void input(){
  fastio
  cin >> N;
  for (int i = 1; i <= N; ++i){
    cin >> h[i];
  }
}

void solve(){
  long long ans = 0;
  stack<int> st;

  for (int i = 1; i <= N; ++i){
    int sz = st.size();
    while (st.size() && h[st.top()] <= h[i]){
      st.pop();
    }
    ans += (sz - st.size()) * st.size();
    ans += (sz - st.size() - 1) * (sz - st.size()) / 2;
    st.push(i);
  }

  ans += (st.size() - 1) * st.size() / 2;
  cout << ans;
}

int main(){
  input();
  solve();
  return 0;
}