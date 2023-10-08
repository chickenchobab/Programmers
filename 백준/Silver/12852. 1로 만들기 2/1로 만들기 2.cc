#include <iostream>
#include <algorithm>

using namespace std;

int n, dp[1000001], bt[1000001];

void print(int num){
    cout<<num<<' ';
    if(num==1) return;
    if(bt[num]==3) print(num-1);
    else if(bt[num]==2) print(num/2);
    else print(num/3);
}

int main(){
    cin>>n;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+1;
        bt[i]=3;
        if(i%2==0) {
            if(dp[i]>dp[i/2]+1) {dp[i]=dp[i/2]+1; bt[i]=2;}
        }
        if(i%3==0) {
            if(dp[i]>dp[i/3]+1) {dp[i]=dp[i/3]+1; bt[i]=1;}
        }
    }

    cout<<dp[n]<<'\n';
    print(n);

}