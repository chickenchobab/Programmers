#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, p, m;
int arr[55];

void input(){
    fastio
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
        if (arr[i] == 1 || arr[i] == 0) continue;
        else if (arr[i] > 0) p ++;
        else m ++;
    }
}

void solve(){

    int sum = 0, s = 1, e = n;
    sort(arr + 1, arr + n + 1);
    
    while (m > 1){ // multiply negatives
        sum += (arr[s] * arr[s + 1]);
        s += 2;
        m -= 2;
    }
    while (p > 1){ // multiply positives
        sum += (arr[e] * arr[e - 1]);
        e -= 2;
        p -= 2;
    }

    if (s <= e){ // if negative remains multiply with zero
        if (arr[s] < 0 && s < e && arr[s + 1] == 0) arr[s] = 0;
        while (s <= e) sum += arr[s ++]; // add the rests
    }

    cout << sum;
}

int main(){
    input();
    solve();
    return 0;
}