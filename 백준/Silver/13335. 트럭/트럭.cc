#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, w, l;
int truck[1001];
queue<pair<int, int>> q;

void input(){
    fastio
    cin >> n >> w >> l;
    for (int i = 1; i <= n; i ++) 
        cin >> truck[i];
}

void solve(){
    int tick = 0, idx = 1, sum = 0;

    while (1) {
        if (q.size() && tick - q.front().second >= w) {
            sum -= truck[q.front().first];
            q.pop();
        }
        if (idx <= n && q.size() + 1 <= w && sum + truck[idx] <= l){
            sum += truck[idx];
            q.push({idx, tick});
            idx ++;
        }
        tick ++;
        if (q.empty()) break;
    }

    cout << tick;
}

int main(){
    input();
    solve();
    return 0;
}