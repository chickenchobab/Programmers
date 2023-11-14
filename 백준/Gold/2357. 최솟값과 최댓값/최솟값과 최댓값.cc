#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

typedef pair<int, int> p;

// one-base segment tree
class Segtree {
 public:
  vector<p> tree;
  int size;

  Segtree(int t) {
    for (size = 1; size < t; size *= 2)
      ;
    tree.resize(size * 2, {1000000000, 1});
  }

  // update
  void update(int pos, int num) {
    int index = size + pos - 1;
    while (index) {
      int mn = tree[index].first;
      int mx = tree[index].second;
      tree[index] = {min(num, mn), max(num, mx)};
      index /= 2;
    }
  }

  p query(int left, int right) { return query(1, 1, size, left, right); }
 
  p query(int pos, int start, int end, int left, int right) {
    if (start > right || end < left) {  // 구하려는 구간이 밖에 있는 경우
      return {1000000000, 1};
    } else if (left <= start &&
               end <= right) {  // 구하려는 구간이 완전히 안에 있는 경우
      return tree[pos];
    } else {  // 구하려는 구간이 걸쳐 있는 경우
      int mid = (start + end) / 2;
      p a = query(pos * 2, start, mid, left, right);
      p b = query(pos * 2 + 1, mid + 1, end, left, right);

      return { min(a.first, b.first), max(a.second, b.second) };
    }
  }

};

ll n,m,a,b;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    
    Segtree seg(n);

    int input;
    for(int i=1; i<=n; i++){
        cin>>input;
        seg.update(i, input);
    }
    for(int i=1; i<=m; i++){
        cin >> a >> b;
        p ans = seg.query(a, b);
        cout << ans.first << ' ' << ans.second << '\n';
    }


    

}