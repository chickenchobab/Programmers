#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10000000000

using namespace std;

int n,c,r,a,b;
long long dp[501][501];
vector<int> p;

int main(){
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) dp[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++){
        cin>>r>>c;
        if(i==1) p.push_back(r);
        p.push_back(c);
    }
    for(int l=2; l<=n; l++){
        for(int i=1; i<=n-l+1; i++){
            int j=i+l-1;
            dp[i][j]=MAX;
            for(int k=i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }

    cout<<dp[1][n];
    
}