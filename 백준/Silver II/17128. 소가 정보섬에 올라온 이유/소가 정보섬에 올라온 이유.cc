#include <iostream>
#include <vector>

using namespace std;

int n, q;
int arr[200002], term[200002];
long long ans;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
        term[i] = arr[i];
    }
    for (int i = 0; i < n; i ++){
        for (int j = i + 1; j <= i + 3; j ++){
            term[i] *= arr[j % n];
        }
        ans += term[i];
    }
}

void query(){
    int idx;
    while (q --){
        cin >> idx;
        idx --;
        for (int i = 0; i <= 3; i ++){
            term[(idx + n - i) % n] *= -1;
            ans += 2 * term[(idx + n - i) % n];
        }
        cout << ans << '\n';
    }
}

int main(){
    init();
    // cout << ans << '\n';
    query();
}