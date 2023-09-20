#include <iostream>
#include <algorithm>

using namespace std;

int n;
int wine[10001];
long long d[10001]={0,};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>wine[i];
    }

    d[0]=0;
    d[1]=wine[1];
    d[2]=wine[1]+wine[2];

    for(int i=3;i<=n;i++){
        d[i]=max(d[i-2], d[i-3]+wine[i-1])+wine[i];
        d[i]=max(d[i],d[i-1]);
    }

    cout<<d[n];
}