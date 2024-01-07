#include <iostream>
#include <algorithm>

using namespace std;

int rope[100001];
int n;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> rope[i];
    }
}

int main(){
    input();
    sort(rope + 1, rope + n + 1);

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        ans = max(ans, rope[i] * (n - i + 1));
    }

    cout << ans;
}