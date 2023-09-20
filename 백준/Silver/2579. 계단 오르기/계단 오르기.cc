#include <iostream>
#include <algorithm>

using namespace std;

int n;
int stair[301];
long long d[301];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stair[i];
    }

    d[0]=0;
    d[1]=stair[1];
    d[2]=stair[1]+stair[2];

    for(int i=3;i<=n;i++){
        d[i]=max(d[i-2],d[i-3]+stair[i-1])+stair[i]; 
    }

    cout<<d[n];
}