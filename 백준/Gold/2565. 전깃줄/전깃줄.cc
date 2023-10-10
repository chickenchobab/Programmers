#include <iostream>
#include <algorithm>

using namespace std;

int n,a,b,arr[501],dp[501];
int i,j;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        arr[a]=b;
        dp[a]=1;
    }
    for(i=1;i<=500;i++){
        for(j=1;j<=i;j++){
            if(arr[i]>arr[j]) dp[i]=max(dp[i],dp[j]+1);
        }
    }   
    sort(dp+1,dp+501);

    cout<<n-dp[500];

}