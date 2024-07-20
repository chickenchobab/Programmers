#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int height[500005];

void input(){
  fastio
  cin >> N;
  for (int i = 1; i <= N; ++i){
    cin >> height[i];
  }
}

void solve(){

  stack<int> st;
  vector<int> receiver(N, 0);

  for (int i = N; i >= 1; --i){
    while (st.size() && height[st.top()] < height[i]){
      receiver[st.top() - 1] = i;
      st.pop();
    }
    st.push(i);
  }

  for (int r : receiver){
    cout << r << ' ';
  }
}  

int main(){
  input();
  solve();
  return 0;
}