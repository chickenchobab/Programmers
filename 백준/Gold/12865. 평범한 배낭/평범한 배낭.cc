#include <iostream>
#include <algorithm>

using namespace std;

//typedef pair<int, int> p;

int n,k;
int dp[100001], v[101], w[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=k;j>=1;j--){
            if(j>=w[i]) dp[j]=max(dp[j-w[i]]+v[i], dp[j]);
        }
    }

    // for(int i=1;i<=k;i++){
    //     cout<<dp[i]<<' ';
    // }
    cout<<dp[k];
    
}