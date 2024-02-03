#include <iostream>
#include <algorithm>
using namespace std;

int n;
int quality[100001];

void input(){
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> quality[i];
    }
}

int main(){
    input();
    sort(quality + 1, quality + n + 1, greater<int>());

    int ans = n % 2 ? quality[n / 2 + 1] : 0;

    for (int i = 1; i <= n / 2; i ++){
        ans += 2 * quality[i];
    }   

    cout << ans;
}