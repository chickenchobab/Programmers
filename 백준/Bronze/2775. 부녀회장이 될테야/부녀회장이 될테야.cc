#include <iostream>
#include <algorithm>

using namespace std;

int t,n,k;
int dp[15][15];
int p(int a, int b){
    if(dp[a][b]) return dp[a][b];
    if(b==1) return dp[a][b]=1;
    if(a==0) return dp[a][b]=b;
    return (dp[a][b]=p(a-1,b)+p(a,b-1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>t;
    fill(&dp[0][0], &dp[14][14],0);
    
    while(t--){
        cin>>n>>k;
        cout<<p(n,k)<<'\n';
    }
}