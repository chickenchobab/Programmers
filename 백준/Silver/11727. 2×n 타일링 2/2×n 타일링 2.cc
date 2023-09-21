#include <iostream>

using namespace std;

int n, dp[1001];

int main(){
    int mod=10000+1+1+1+1+1+1+1;
    cin>>n;
    dp[1]=dp[0]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]+2*dp[i-2])%mod;
    }
    cout<<dp[n];
}