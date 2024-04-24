#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, r, c;
int cnt, ans;

void input(){
    fastio
    cin >> n >> r >> c;
}

void visit(int i, int j, int sz){
    if (!(i <= r && r < i + sz && j <= c && c < j + sz)){
        cnt += sz * sz;
        return;
    }
    if (sz == 1){
        if (i == r && j == c) {
            cout << cnt;
            exit(0);
        }
        cnt ++;
        return;
    }
    visit(i, j, sz / 2);
    visit(i, j + sz / 2, sz / 2);
    visit(i + sz / 2, j, sz / 2);
    visit(i + sz / 2, j + sz / 2, sz / 2);
}

void solve(){
    int sz = 1;
    while (n --) sz *= 2;
    visit(0, 0, sz);
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}