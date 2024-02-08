#include <iostream>

using namespace std;

int k;
int tree[1<<10];

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> k;
}

void solve(int idx){
    if (idx > ((1 << k) - 1)) return;
    solve(idx * 2);
    cin >> tree[idx];
    solve(idx * 2 + 1);
}

void print(){
    for (int i = 1; i <= (1 << k - 1); i *= 2){
        for (int j = i; j < (i << 1); j ++){
            cout << tree[j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    input();
    solve(1);
    print();
}