#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void input(){
  fastio
}

void solve(){
  int ans = 0;
  char ch;
  stack<char> st;

  bool isAroundCanon = 0;

  while (1){
    ch = cin.get();
    if (ch == '\n') break;

    if (ch == '(') {
      st.push(ch);
      isAroundCanon = 0;
    }
    else { // )
      if (isAroundCanon) {
        st.pop();
        ans++;
      }
      else {
        st.pop();
        ans += st.size();
        isAroundCanon = 1;
      }
    }
  }

  cout << ans;
}

int main(){
  input();
  solve();
  return 0;
}