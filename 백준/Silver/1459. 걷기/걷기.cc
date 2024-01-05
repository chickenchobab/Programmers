#include <iostream>
#include <algorithm>

using namespace std;

long long x, y, w, s;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y >> w >> s;
    if (x < y) swap(x, y);
}

long long solve(){
    if (2 * w <= s) return (x + y) * w;
    if (w <= s) return (x - y) * w + y * s;
    if ((x + y) % 2 == 0) return x * s;
    return (x - 1) * s + w;
}

int main(){

    input();
    cout << solve();

}