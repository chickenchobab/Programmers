#include <iostream>
#include <algorithm>
#include <set>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int arr[2002];
set<int> visited;

void input(){
    fastio
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
        visited.insert(arr[i]);
    }
}

void solve(){ 
    int ans = 0;
    sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; ++ i){
        int s = 1, e = n;
        while (s < e){
            if (s == i) s ++;
            if (e == i) e --;
            if (s >= e) break;
            int sum = arr[s] + arr[e];
            if (sum > arr[i]) e --;
            else if (sum < arr[i]) s ++;
            else {
                ans ++;
                break;
            }
        }
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}