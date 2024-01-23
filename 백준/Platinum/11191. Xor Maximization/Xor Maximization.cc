#include <iostream>
#include <algorithm>
#define LEN (64)

using namespace std;

typedef long long ll;
int n;
ll arr[LEN];

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll tmp;
    for (int i = 0; i < n; i ++){
        cin >> tmp;
        for (int j = LEN - 1; j >= 0; j --){
            if (((tmp >> j) & 1) == 0) continue;

            if (arr[j]) tmp ^= arr[j]; 
            else {
                arr[j] = tmp; 
                break;
            }
        }
    }
    tmp = 0;
    for (int i = LEN - 1; i >= 0; i --){
        tmp = max(tmp, tmp ^ arr[i]);
    }
    cout << tmp;
}

int main(){
    solve();
}