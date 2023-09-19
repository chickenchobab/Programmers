#include <iostream>
#define MAX 1000000000

using namespace std;

int n, dp[101][10];
long long sum;

int main(){
    cin>>n;
    
    for(int i=0;i<=9;i++){
        if(i) dp[1][i]=1;
        else dp[1][i]=0;
    }

    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){

            if(j==0) dp[i][j]=dp[i-1][j+1];
            else if(j==9) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MAX;
        }
    }
    
    for(int i=0;i<=9;i++){
        sum=(sum+dp[n][i])%MAX;
    }
    cout<<sum;
}