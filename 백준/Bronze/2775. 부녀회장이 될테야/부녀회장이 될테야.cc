#include <iostream>
#include <algorithm>

using namespace std;

int t,n,k;
int dp[15][15];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>t;
    fill(&dp[0][0], &dp[14][14],0);
    for(int i=0;i<=14;i++){
        for(int j=1;j<=14;j++){
            if(i==0) dp[i][j]=dp[i][j-1]+j;
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    
    while(t--){
        cin>>n>>k;
        cout<<dp[n][k]-dp[n][k-1]<<'\n';
    }
}