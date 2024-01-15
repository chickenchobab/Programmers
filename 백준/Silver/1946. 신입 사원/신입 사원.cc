#include <iostream>
#include <algorithm>

using namespace std;

int t;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
}

int solve(){
    int n, a, b, c = 0;
    pair<int, int> rank[100001];
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a >> b;
        rank[i] = {a, b};
    }
    sort(rank + 1, rank + n + 1);

    b = rank[1].second;
    for (int i = 2; i <= n; i ++){
        if (rank[i].second < b) {
            b = rank[i].second;
            continue;
        }
        c ++;
    }
    return n - c;
}

int main(){
    input();
    while (t --){
        cout << solve() << '\n';
    }
}