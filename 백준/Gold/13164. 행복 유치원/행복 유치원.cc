#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int gap[300003];

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> k;
    int prv, cur;

    cin >> prv;
    for (int i = 1; i < n ; i ++){
        cin >> cur;
        gap[i] = cur - prv;
        prv = cur;
    }
}

int main(){
    input();
    sort(gap + 1, gap + n);

    int sum = 0;
    for (int i = 1; i <= n - 1 - (k - 1); i ++){
        sum += gap[i];
    }

    cout << sum;
}