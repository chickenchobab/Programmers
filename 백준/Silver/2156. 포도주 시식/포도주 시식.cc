#include <iostream>
#include <algorithm>

using namespace std;

int n;
int score[10001];
long long dp[10001];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>score[i];
    }
    dp[1]=score[1];
    dp[2]=score[1]+score[2];
    dp[3]=max(score[1],score[2])+score[3];
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i-2], max(dp[i-4]+score[i-1], dp[i-3]+score[i-1]))+score[i];
    }

    sort(dp+1, dp+n+1);
    cout<<dp[n];
}