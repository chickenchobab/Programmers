#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s1, s2;
int l1,l2,dp[1001][1001];

int main(){
    cin>>s1>>s2;
    l1=s1.length(), l2=s2.length();

    for(int i=0; i<=l1; i++) dp[i][0]=0;
    for(int j=0; j<=l2; j++) dp[0][j]=0;

    for(int i=1; i<=l1 ;i++){
        for(int j=1; j<=l2; j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    cout<<dp[l1][l2];

}