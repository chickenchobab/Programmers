#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, k;
int arr[200002];
int cnt[100001];

void input(){
    fastio
    cin >> n >> k;
}

void solve(){ 

    int s = 1, e = 1, ans = 1;
    for (e = 1; e <= n; e ++) {
        cin >> arr[e];
        cnt[arr[e]] ++;
        while (cnt[arr[e]] > k) {
            cnt[arr[s]] --;
            s ++;
        }
        ans = max(ans, e - s + 1);
    }
    cout << ans;
}


int main(){
    input();
    solve();
    return 0;
}