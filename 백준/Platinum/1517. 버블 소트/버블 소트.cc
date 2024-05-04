#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using etype = int;

int n;
int arr[500005];
long long ans;

void input(){
    fastio
    cin >> n;
    int num;
    for (int i = 1; i <= n; i ++) {
      cin >> arr[i];
    }
}

void merge(int p, int q, int r){
  int i = p, j = q + 1, t = 0;
  int tmp[r - p + 1];
  while (i <= q && j <= r){
    if (arr[i] <= arr[j]) tmp[t ++] = arr[i ++];
    else {
      ans += abs(j - (p + t));
      tmp[t ++] = arr[j ++];
    }
  }
  while (i <= q) tmp[t ++] = arr[i ++];
  while (j <= r) tmp[t ++] = arr[j ++];
  t = 0;
  for (i = p; i <= r; i ++)
    arr[i] = tmp[t ++];
}

void merge_sort(int p, int r){
  if (p < r){
    int q = (p + r) / 2;
    merge_sort(p, q);
    merge_sort(q + 1, r);
    merge(p, q, r);
  }
}

void solve(){
    merge_sort(1, n);
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}