#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> p;
typedef long long ll;

struct w{
    bool operator()(p &a, p &b){
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
struct v{
    bool operator()(p &a, p &b){
        if (a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }
};
int n, m, capacity[300001];
priority_queue<p, vector<p>, w> jewel;
priority_queue<p, vector<p>, v> jewel_capable;

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    //jewel[0] = {0, 0};
    int a, b;
    for (int i = 1; i <= n; i ++){
        cin >> a >> b;
        jewel.push({a, b});
    }
    for (int i = 1; i <= m; i ++){
        cin >> capacity[i];
    }
}

int main(){
    input();

    sort(capacity + 1, capacity + m + 1);

    ll ans = 0;

    for (int i = 1; i <= m; i ++){
        while (jewel.size() && jewel.top().first <= capacity[i]) {
            jewel_capable.push(jewel.top());
            jewel.pop();
        }
        if (jewel_capable.size()){
            ans += jewel_capable.top().second;
            jewel_capable.pop();
        }
    }
    cout << ans;
     
}