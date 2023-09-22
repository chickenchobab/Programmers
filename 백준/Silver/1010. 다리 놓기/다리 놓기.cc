#include <iostream>

using namespace std;

int t,n,m;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        int dp[30];
        dp[1]=m;

        for(int i=2;i<=n;i++){
           dp[i]=dp[i-1]*(m-i+1)/i;
        }
      
        cout<<dp[n]<<'\n';
        
    }
}