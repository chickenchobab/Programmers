#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

int t;
int a, b, c;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
}

int solve(){
    for (c = 0; c <= t / 10; c ++){

        if ((t - c * 10) % 60 != 0) continue;

        for (b = 0; b <= (t - c * 10) / 60; b ++){

            if ((t - c * 10 - b * 60) % 300 != 0) continue;

            a = (t - c * 10 - b * 60) / 300;
            return 0; 
        }
        if ((t - c * 10 - b * 60 - a * 300) == 0)
            return 0;
    } 
    return -1;
}

int main(){
    input();
    solve() ? cout << -1 : cout << a << ' ' << b << ' ' << c;
}