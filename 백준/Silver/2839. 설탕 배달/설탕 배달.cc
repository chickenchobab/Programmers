#include <iostream>
#include <algorithm>
#define MAX 22222
using namespace std;

int n;
// int arr[5005];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
}

int main(){
    input();

    int cnt = 0, flag = 0;

    for (int i = 0; i <= n / 3; i ++){
        if ((n - 3 * i) % 5) continue;
        cnt = (n - 3 * i) / 5 + i;
        flag = 1;
        break;
    }

    flag ? cout << cnt : cout << -1;

}       