#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 123456789
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int t;
int n;

typedef long long ll;

void input(){
    fastio
    cin >> t;
}

void solve(){
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;

    cin >> n;
    int file;
    for (int i = 1; i <= n; i ++){
        cin >> file;
        pq.push(file);
    }

    while (pq.size() > 1){
        ll u = pq.top();
        pq.pop();
        ll v = pq.top();
        pq.pop();

        sum += (u + v);
        pq.push(u + v);
    }

    cout << sum << '\n';
}

int main(){
    input();
    while (t --){
        solve();
    }
    return 0;
}