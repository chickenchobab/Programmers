#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
int n;
ii arr[2][3];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin >> n >> a >> b >> c;
    arr[0][0] = {a, a}; arr[0][1] = {b, b}; arr[0][2] = {c, c};

    for (int i = 1; i < n; i ++){
        cin >> a >> b >> c;
        arr[i % 2][0] = {a + max(arr[(i + 1) % 2][0].first, arr[(i + 1) % 2][1].first), a + min(arr[(i + 1) % 2][0].second, arr[(i + 1) % 2][1].second)};
        arr[i % 2][1] = {b + max(arr[(i + 1) % 2][0].first, max(arr[(i + 1) % 2][1].first, arr[(i + 1) % 2][2].first)), b + min(arr[(i + 1) % 2][0].second, min(arr[(i + 1) % 2][1].second, arr[(i + 1) % 2][2].second))};
        arr[i % 2][2] = {c + max(arr[(i + 1) % 2][1].first, arr[(i + 1) % 2][2].first), c + min(arr[(i + 1) % 2][1].second, arr[(i + 1) % 2][2].second)};
    }
}

int main(){
    input();
    int mx = 0, mn = 999999;
    for (int i = 0; i < 3; i ++){
        mx = max(mx, arr[(n + 1) % 2][i].first);
        mn = min(mn, arr[(n + 1) % 2][i].second);
    }
    cout << mx << ' ' << mn;
}