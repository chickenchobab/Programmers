#include <iostream>
#include <algorithm>

using namespace std;

int n, dp[5001];

int main(){
    cin>>n;
    for(int i=3;i<=5;i+=2){
        for(int j=1;j<=n;j++){
            if(j%i==0) dp[j]=j/i;
            if(dp[j-i]) {
                if(dp[j]) dp[j]=min(dp[j], dp[j-i]+1);
                else dp[j]=dp[j-i]+1;
            }
        }
    }
    
    cout<<(dp[n]? dp[n]:-1);


}