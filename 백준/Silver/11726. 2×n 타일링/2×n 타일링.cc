#include <iostream>

using namespace std;

int n, dp[1001][3];
int main(){
    cin>>n;
    int mod=10000+1+1+1+1+1+1+1;
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][2]=0;

    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i][1]=(dp[i-1][0]+dp[i-1][2])%mod;
        dp[i][2]=dp[i-1][1];
    }
    cout<<(dp[n][0]+dp[n][2])%mod;
}