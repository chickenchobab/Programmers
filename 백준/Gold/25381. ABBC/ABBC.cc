#include <iostream>
#include <algorithm>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string S;

void input(){
  fastio
  cin >> S;
}

void solve(){
  int removeCnt = 0;
  int BCnt = 0, CCnt = 0;
  
  for (int i = S.length() - 1; i >= 0; --i){

    if (S[i] == 'C'){
      ++CCnt;
    }
    else if (S[i] == 'B'){
      if (CCnt) {
        ++removeCnt;
        --CCnt;
      }
      else {
        ++BCnt;
      }
    }
    else {
      if (BCnt) {
        ++removeCnt;
        --BCnt;
      }
    }      
  }

  cout << removeCnt;

}

int main(){
  input();
  solve();
  return 0;
}