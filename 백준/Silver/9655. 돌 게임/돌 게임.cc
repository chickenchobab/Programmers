#include <iostream>

using namespace std;

int n;
bool dp[1001];

int main(){
    cin >> n;

    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    for (int i = 3; i <= n; i ++){
        dp[i] = !dp[i - 3];
    }

    dp[n] ? cout << "SK" : cout << "CY";

}