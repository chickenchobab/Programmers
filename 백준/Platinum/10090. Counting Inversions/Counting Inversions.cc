#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using etype = long long;

int n;
pair<int, int> arr[1000001];

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
  void update(int pos, etype diff) {
    int index = size + pos - 1;
    while (index) {
      tree[index] += diff;
      index /= 2;
    }
  }

  etype query(int left, int right) { return query(1, 1, size, left, right); }

  etype query(int pos, int start, int end, int left, int right) {
    if (start > right || end < left) {  // 구하려는 구간이 밖에 있는 경우
      return 0;
    } else if (left <= start && end <= right) {  // 구하려는 구간이 완전히 안에 있는 경우
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

void solve(){
    long long ans = 0;
    Segtree segtree(n);
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i ++){
        ans += (long long) segtree.query(arr[i].second, n);
        segtree.update(arr[i].second, 1);
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}