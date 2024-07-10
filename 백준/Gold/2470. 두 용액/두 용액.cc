#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000000000
using namespace std;
int N;
int arr[100000];
// vector<int> p, m;

void input(){
  fastio
  cin >> N;
  // int num;
  for (int i = 0; i < N; ++ i)
    cin >> arr[i];
}

void solve(){
  int s, e, i, j, sum, tmp;

  sort(arr, arr + N);
  s = 0; e = N - 1;
  sum = MAX + MAX + 1;

  while (s < e){
    tmp = arr[s] + arr[e];

    if (abs(tmp) < sum){
      sum = abs(tmp);
      i = s; j = e;
    }
    if (sum == 0) break;

    if (tmp < 0) s ++;
    else e --;
  }

  cout << arr[i] << ' ' << arr[j];
}

int main(){
  input();
  solve();
  return 0;
}