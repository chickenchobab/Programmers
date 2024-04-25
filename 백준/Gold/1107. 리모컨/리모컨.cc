#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
bool broken[10];

void input(){
    fastio
    cin >> n >> m;
    int btn;
    for (int i = 0; i < m; i ++){
        cin >> btn;
        broken[btn] = 1;
    }
}

int is_valid(int x){
    int len = 0;
    if (x == 0) return !broken[0];
    while (x){
        if (broken[x % 10]) return 0;
        x /= 10;
        len ++;
    }
    return len;
}

int bfs(){
    int ans = abs(n - 100);

    for (int i = 0; i <= 1000000; i++){
        int len = is_valid(i);
        if (len){
            int press = abs(i - n) + len;
            ans = min(ans, press);
        }
    }
    return ans;
}

void solve(){
    int ans;
    ans = bfs();
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}