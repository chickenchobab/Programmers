#include <iostream>
#include <algorithm>

using namespace std;

int t,n,dp[11];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>t;
    dp[1]=1, dp[2]=2, dp[3]=4;
        for(int i=4;i<=10;i++){
            dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
        }
    while(t--){
        cin>>n;
        cout<<dp[n]<<'\n';
    }   

}