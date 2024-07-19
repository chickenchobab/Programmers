#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int A[1000001], NGF[10000001];
unordered_map<int, int> frequency;

void input(){
  fastio
  cin >> N;
  int num;
  for (int i = 1; i <= N; ++i){
    cin >> A[i];
    frequency[A[i]]++;
  }
}

void solve(){
  stack<int> st;

  for (int i = 1; i <= N; ++i){
    while (st.size() && frequency[A[st.top()]] < frequency[A[i]]){
      NGF[st.top()] = A[i];
      st.pop();
    }
    st.push(i);
  }

  while (st.size()){
    NGF[st.top()] = -1;
    st.pop();
  }

  for (int i = 1; i <= N; ++i){
    cout << NGF[i] << ' ';
  }
}

int main(){
  input();
  solve();
  return 0;
}