#include <iostream>
#include <algorithm>
#include <string>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string s, t;

void input(){
  fastio
  cin >> s >> t;
}

bool cmp(bool reversed){ 
  int len = s.length();

  if (reversed){
    for (int i = 0; i < len; ++ i){
      if (s[i] != t[len - 1 - i]) return false;
    }
  }
  else {
    for (int i = 0; i < len; ++ i){
      if (s[i] != t[i]) return false;
    }
  }
  return true;
}

void solve(){
  int len = s.length();
  int turn = 0; 

  while (t.length() != len){
    int l = t.length();
    if (turn % 2){
      if (t[0] == 'A');
      else turn ++;
      t = t.substr(1);
    }
    else{
      if (t[l - 1] == 'A');
      else turn ++;
      t.pop_back();
    }
  }
  
  // cout << s << ' ' << t << '\n';
  cout << cmp(turn % 2);
}

int main(){
  input();
  solve();
  return 0;
}