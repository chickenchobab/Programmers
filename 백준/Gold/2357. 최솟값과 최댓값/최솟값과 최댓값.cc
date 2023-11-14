#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// one-base segment tree
class Segtree {
 public:
  vector<ll> tree;
  int size;

  Segtree(int t, int option) {
    for (size = 1; size < t; size *= 2)
      ;
    if(option == 1)
    tree.resize(size * 2, 1);
    else
    tree.resize(size * 2, 1000000000);
  }

  // update
  void update1(int pos, ll num) {
    int index = size + pos - 1;
    ll diff = num - tree[index];
    while (index) {
      tree[index] = max(num, tree[index]);
      index /= 2;
    }
  }

  void update2(int pos, ll num) {
    int index = size + pos - 1;
    ll diff = num - tree[index];
    while (index) {
      tree[index] = min(num, tree[index]);
      index /= 2;
    }
  }

 ll query1(int left, int right) { return query1(1, 1, size, left, right); }
 ll query2(int left, int right) { return query2(1, 1, size, left, right); }

  ll query1(int pos, int start, int end, int left, int right) {
    if (start > right || end < left) {  // 구하려는 구간이 밖에 있는 경우
      return 1;
    } else if (left <= start &&
               end <= right) {  // 구하려는 구간이 완전히 안에 있는 경우
      return tree[pos];
    } else {  // 구하려는 구간이 걸쳐 있는 경우
      int mid = (start + end) / 2;
      return max(query1(pos * 2, start, mid, left, right) ,
             query1(pos * 2 + 1, mid + 1, end, left, right));
    }
  }

  ll query2(int pos, int start, int end, int left, int right) {
    if (start > right || end < left) {  // 구하려는 구간이 밖에 있는 경우
      return 1000000000;
    } else if (left <= start &&
               end <= right) {  // 구하려는 구간이 완전히 안에 있는 경우
      return tree[pos];
    } else {  // 구하려는 구간이 걸쳐 있는 경우
      int mid = (start + end) / 2;
      return min(query2(pos * 2, start, mid, left, right) ,
             query2(pos * 2 + 1, mid + 1, end, left, right));
    }
  }
};

ll n,m,a,b;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    Segtree seg1(n, 1);
    Segtree seg2(n, 2);
    int input;
    for(int i=1; i<=n; i++){
        cin>>input;
        seg1.update1(i,input);
        seg2.update2(i,input);
    }
    for(int i=1; i<=m; i++){
        cin>>a>>b;
        cout<<seg2.query2(a,b)<<' '<<seg1.query1(a,b)<<'\n';
    }


    

}