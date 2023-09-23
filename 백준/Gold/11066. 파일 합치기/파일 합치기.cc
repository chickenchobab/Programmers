#include <iostream>
#include <algorithm>

using namespace std;

int t,n,sum[501],dp[501][501];

int main(){
    cin>>t;
    while(t--){
        cin>>n;

        int cost;
        for(int i=1;i<=n;i++){
            cin>>cost;
            sum[i]=sum[i-1]+cost;
        }

        for(int s=1; s<=n; s++){
            for(int a=1; a<=n-s; a++){
                int b=a+s;
                dp[a][b]=100000000;
                for(int mid=a; mid<b; mid++){
                    dp[a][b]=min(dp[a][b], dp[a][mid]+dp[mid+1][b]+(sum[b]-sum[a-1]));
                }
            }
        }

        cout<<dp[1][n]<<'\n';
    }
}