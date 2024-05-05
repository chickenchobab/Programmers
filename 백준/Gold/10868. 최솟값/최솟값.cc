#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, m;
using namespace std;
using etype = int;

// one-base segment tree
class Segtree {
 public:
  vector<etype> tree;
  int size;

  Segtree(int t) {
    for (size = 1; size < t; size *= 2);
    tree.resize(size * 2, 1000000000);
  }

  // update
  void update(int pos, etype num) {
    int index = size + pos - 1;
    tree[index] = num;
    index /= 2;
    while (index) {
      tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
      index /= 2;
    }
  }

  etype query(int left, int right) { return query(1, 1, size, left, right); }

  etype query(int pos, int start, int end, int left, int right) {
    if (start > right || end < left) {  // 구하려는 구간이 밖에 있는 경우
      return 1000000000;
    } else if (left <= start && end <= right) {  // 구하려는 구간이 완전히 안에 있는 경우
      return tree[pos];
    } else {  // 구하려는 구간이 걸쳐 있는 경우
      int mid = (start + end) / 2;
      return min(query(pos * 2, start, mid, left, right),
             query(pos * 2 + 1, mid + 1, end, left, right));
    }
  }
};


void input(){
    fastio
    cin >> n >> m;
}

void solve(){
    Segtree segtree(n);
    int num, a, b;
    for (int i = 1; i <= n; ++ i) {
        cin >> num;
        segtree.update(i, num);
    }
    for (int i = 1; i <= m; ++ i){
        cin >> a >> b;
        cout << segtree.query(a, b) << '\n';
    }
}

int main(){
    input();
    solve();
    return 0;
}