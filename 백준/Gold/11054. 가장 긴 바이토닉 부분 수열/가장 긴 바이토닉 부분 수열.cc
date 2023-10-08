#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1001],d1[1001],d2[1001];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        d1[i]=d2[i]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i; j++){
            if(arr[j]<arr[i]) d1[i]=max(d1[i],d1[j]+1);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=n;j>=i;j--){
            if(arr[i]>arr[j]) d2[i]=max(d2[i], d2[j]+1);
        }
    }

    int l=0;
    for(int k=1; k<=n; k++){
        l=max(l,d1[k]+d2[k]);
    }

    //cout<<dp[1][n];
    cout<<l-1;
}