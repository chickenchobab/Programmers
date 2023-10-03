#include <iostream>
#include <algorithm>

using namespace std;

int n,c[1001][3],dp[1001][3];
int ans=1111111;

int main(){

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            cin>>c[i][j];
        }
    }

    //1번에서 0선택
    dp[1][0]=c[1][0];
    dp[1][1]=dp[1][2]=1001;
    for(int i=2;i<=n;i++){
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+c[i][0];
        dp[i][1]=min(dp[i-1][2],dp[i-1][0])+c[i][1];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+c[i][2];
    }
    ans=min(ans,min(dp[n][1],dp[n][2]));

    //1번에서 1선택
    dp[1][1]=c[1][1];
    dp[1][0]=dp[1][2]=1001;
    for(int i=2;i<=n;i++){
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+c[i][0];
        dp[i][1]=min(dp[i-1][2],dp[i-1][0])+c[i][1];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+c[i][2];
    }
    ans=min(ans,min(dp[n][2],dp[n][0]));

    //1번에서 2선택
    dp[1][2]=c[1][2];
    dp[1][0]=dp[1][1]=1001;
    for(int i=2;i<=n;i++){
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+c[i][0];
        dp[i][1]=min(dp[i-1][2],dp[i-1][0])+c[i][1];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+c[i][2];
    }
    ans=min(ans,min(dp[n][0],dp[n][1]));

    cout<<ans;
}