#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;
int weight[26];

void input(){
    fastio
    string str;
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> str;
        int l = str.length(), w = 1;
        for (int j = l - 1; j >= 0; j --, w *= 10){
            weight[str[j] - 'A'] += w;
        }
    }
}

void solve(){
    int sum = 0, num = 9, idx = 0;
    sort(weight, weight + 26, greater<int>());
    while (num){
        sum += weight[idx ++] * (num --);
    }
    cout << sum;
}

int main(){
    input();
    solve();
    return 0;
}