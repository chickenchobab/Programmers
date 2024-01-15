#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

string n;

int input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int sum = 0, flag = 0;
    cin >> n;
    for (int i = 0; i < n.length(); i ++){
        if (n[i] == '0') flag = 1;
        sum += (n[i] - '0');
    }
    if (sum % 3 == 0 && flag) return 1;
    return 0;
}

int main(){
    if (input()){
        sort(n.begin(), n.end(), greater<int>());
        cout << n;
        return 0;
    }
    cout << -1;
}