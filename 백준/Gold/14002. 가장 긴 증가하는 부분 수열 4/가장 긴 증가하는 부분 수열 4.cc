#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int arr[1001];
int dp[1001], bt[1001];

void input(){
    fastio
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> arr[i];
    }
}

void printarr(int idx){
    if (idx == 0) return;
    printarr(bt[idx]);
    cout << arr[idx] << ' ';
}

void solve(){
    int len = 0, idx = 0;
    for (int i = 1; i <= n; i ++){
        dp[i] = 1;
        for (int j = 1; j < i; j ++){
            if (arr[i] <= arr[j]) continue;
            if (dp[i] < dp[j] + 1){
                bt[i] = j;
                dp[i] = dp[j] + 1;
            }         
        }
    }
    for (int i = 1; i <= n; i ++){
        if (len < dp[i]){
            len = dp[i];
            idx = i;
        }
    }
    cout << len << '\n';
    printarr(idx);
}

int main(){
    input();
    solve();
    return 0;
}