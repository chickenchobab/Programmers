#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int n;
int inorder[100001], postorder[100001];
int index[100001];

void input(){
  fastio
  cin >> n;
  for (int i = 1; i <= n; ++ i){
    cin >> inorder[i];
    index[inorder[i]] = i;
  }
  for (int i = 1; i <= n; ++ i){
    cin >> postorder[i];
  }
}

void make_tree(int s, int e, int p){
  if (s >= e) return;
  if (p < 1 || p > n) return;

  int i = index[postorder[p]];
  cout << postorder[p] << ' ';
  make_tree(s, i, p - (e - i));
  make_tree(i + 1, e, p - 1);
}

void solve(){
  make_tree(1, n + 1, n);
}

int main(){
  input();
  solve();
  return 0;
}