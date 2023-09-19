#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long dp[501][501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;

    int tmp;

    for(int i=1;i<=n;i++){
        for(int j=1; j<=i; j++){
            cin>>tmp;
            if(j==1) dp[i][j]=dp[i-1][1]+tmp;
            if(j==i) dp[i][j]=dp[i-1][j-1]+tmp;
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+tmp;
        }
    }

    sort(dp[n]+1, dp[n]+n+1);
    cout<<dp[n][n];
}