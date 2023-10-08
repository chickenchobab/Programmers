#include <iostream>
#include <algorithm>
#define div 1000000000

using namespace std;

int n,k;
long long dp[201][201];
long long f(int a, int b){
    if(dp[a][b]) return dp[a][b];
    if(a==0 || b==1) return dp[a][b]=1;
    long long sum=0;
    for(int i=0;i<=a;i++){
        sum=(sum+f(a-i,b-1))%div;
    }
    return dp[a][b]=sum;
}

int main(){
    cin>>n>>k;

    fill(&dp[0][0], &dp[n][k],0);

    f(n,k);
    cout<<dp[n][k];
    return 0;
}