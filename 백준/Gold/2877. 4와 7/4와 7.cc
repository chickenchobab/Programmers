#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int k;

void input(){
    fastio
    cin >> k;
}

void print(int idx){
    if (idx == 1) return;
    print(idx / 2);
    if (idx % 2 == 0) cout << 4;
    else cout << 7;
}

int main(){
    input();
    print(k + 1);
    return 0;
}