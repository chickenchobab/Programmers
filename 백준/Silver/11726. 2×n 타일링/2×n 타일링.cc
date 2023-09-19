#include <iostream>
#include <algorithm>

using namespace std;

int n, dp[1001];
int main(){
    ios::sync_with_stdio(false);

    cin>>n;
    int mod=10000+1+1+1+1+1+1+1;
    dp[1]=1, dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    cout<<dp[n];
}