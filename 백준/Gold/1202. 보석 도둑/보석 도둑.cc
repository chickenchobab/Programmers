#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> p;
typedef long long ll;

int n, m;
int capacity[300001];

p jewel[300001];

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    //jewel[0] = {0, 0};
    int a, b;
    for (int i = 1; i <= n; i ++){
        cin >> a >> b;
        jewel[i] = {a, b};
    }
    for (int i = 1; i <= m; i ++){
        cin >> capacity[i];
    }
}

int main(){
    input();

    sort(jewel + 1, jewel + n + 1);
    sort(capacity + 1, capacity + m + 1);

    ll ans = 0;
    priority_queue<int> jewel_capable;
    int idx = 1;
    for (int i = 1; i <= m; i ++){

        while(idx <= n && jewel[idx].first <= capacity[i]) {
            jewel_capable.push(jewel[idx].second);
            idx ++;
        }
        
        if (jewel_capable.size()) {
            ans += jewel_capable.top();
            jewel_capable.pop();
        }
    }
    cout << ans;
     
}