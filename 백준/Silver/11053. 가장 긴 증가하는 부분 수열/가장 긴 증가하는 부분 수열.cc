#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1001];
int d[1001];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        d[i]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(arr[j]>arr[i]){
                d[j]=max(d[i]+1,d[j]);
            }
        }
    }

    int m=0;
    for(int i=1;i<=n;i++){
        m=max(d[i],m);
    }

    cout<<m;

}