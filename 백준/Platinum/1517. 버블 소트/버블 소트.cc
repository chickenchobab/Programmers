#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using etype = int;

int n;
pair<int, int> arr[500005];
long long ans;
// one-base segment tree
class Segtree {
 public:
  vector<etype> tree;
  int size;

  Segtree(int t) {
    for (size = 1; size < t; size *= 2);
    tree.resize(size * 2);
  }

  // update
  void update(int pos, etype num) {
    int index = size + pos - 1;
    tree[index] = num;
    while (index) {
      if (tree[index * 2] > tree[index * 2 + 1]) {
        tree[index] = tree[index * 2];
        ans ++;
      }
      else {
        tree[index] = tree[index * 2 + 1];
      }
      index /= 2;
    }
  }

  etype query(int left, int right) { return query(1, 1, size, left, right); }

  etype query(int pos, int start, int end, int left, int right) {
    if (start > right || end < left) {  // 구하려는 구간이 밖에 있는 경우
      return 0;
    } else if (left <= start && end <= right) { // 구하려는 구간이 완전히 안에 있는 경우
      return tree[pos];
    } else {  // 구하려는 구간이 걸쳐 있는 경우
      int mid = (start + end) / 2;
      return query(pos * 2, start, mid, left, right) +
             query(pos * 2 + 1, mid + 1, end, left, right);
    }
  }
};

void input(){
    fastio
    cin >> n;
    int num;
    for (int i = 1; i <= n; i ++) {
      cin >> num;
      arr[i] = {num, i};
    }
}

void merge(int p, int q, int r){
  int i = p, j = q + 1, t = 0;
  int tmp[r - p + 1];
  while (i <= q && j <= r){
    if (arr[i].first <= arr[j].first) {
      tmp[t ++] = arr[i].first;
      i ++;
    }
    else {
      ans += abs(j - (p + t));
      tmp[t ++] = arr[j].first;
      j ++;
    }
  }
  while (i <= q) {tmp[t ++] = arr[i].first; i ++;}
  while (j <= r) {tmp[t ++] = arr[j].first; j ++;}
  t = 0;
  for (i = p; i <= r; i ++){
    arr[i] = {tmp[t ++], i};
  }
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
    // sort(arr + 1, arr + n + 1);
    merge_sort(1, n);
    // for (int i = 1; i <= n; i ++) cout << arr[i].first << ' ';
    // cout << '\n';
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}