#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using ll = long long;

int n, m, input, order, l, r;
typedef pair<int, int> ii;

// one-base segment tree
class Segtree {
 public:
  vector<ii> tree;
  int size;

  Segtree(int t) {
    for (size = 1; size < t; size *= 2)
      ;
    tree.resize(size * 2, {0,0});
  }

  // update
  void update(int pos, int input) {
    int index = size + pos - 1;
    int leaf = index;
        
    while (index) {  

      if(index == leaf) {
        if (input % 2 == 0) tree[index] = {1, 0};
        else tree[index] = {0, 1};
      }
      else {
        ii c1 = tree[2*index];
        ii c2 = tree[2*index+1];
        tree[index] = {c1.first + c2.first, c1.second + c2.second};
       }
      index /= 2;
    }
  }

  ii query(int left, int right) { return query(1, 1, size, left, right); }

  ii query(int pos, int start, int end, int left, int right) {
    if (start > right || end < left) {  // 구하려는 구간이 밖에 있는 경우
      return {0, 0};
    } else if (left <= start &&
               end <= right) {  // 구하려는 구간이 완전히 안에 있는 경우
      return tree[pos];
    } else {  // 구하려는 구간이 걸쳐 있는 경우
      int mid = (start + end) / 2;
      ii a = query(pos * 2, start, mid, left, right);
      ii b = query(pos * 2 + 1, mid + 1, end, left, right);
      return {a.first + b.first, a.second + b.second};
    }
  }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    Segtree seg(n);
    for(int i=1; i<=n; i++){
        cin >> input;
        seg.update(i, input);
    }

    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> order >> l >> r;
        if (order == 1) 
            seg.update(l, r);
        else{
            ii ans = seg.query(l,r);
            if(order == 2) cout << ans.first << '\n';
            else cout << ans.second << '\n';
        }
    }
    
}