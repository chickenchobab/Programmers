#include <iostream> 

using namespace std;

int n,k;
long long dp[1001][1001];

int main(){

    int mod = 10000+1+1+1+1+1+1+1;

    cin>>n>>k;

    dp[0][0]=1;

    for(int i=1;i<=n;i++){
        dp[i][0]=1, dp[i][i]=1;
        for(int j=1;j<=i-1;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            dp[i][j]=dp[i][j]%mod;
        }
    }

    cout<<dp[n][k];



}