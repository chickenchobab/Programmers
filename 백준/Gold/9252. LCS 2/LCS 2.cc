#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string s1, s2;
int l1, l2, dp[1001][1001];

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> s1 >> s2;
    l1 = s1.length();
    l2 = s2.length();
}

void print(int i, int j){
    if (dp[i][j] == 0) return;

    // 재귀로 처음으로 올라간다
    if (s1[i - 1] == s2[j - 1]) 
        print(i - 1, j - 1);
    else 
        dp[i - 1][j] > dp[i][j - 1] ? print(i - 1, j) : print(i, j - 1);
    
    // 거꾸로 내려오면서 유효 문자만 출력한다
    if (s1[i - 1] == s2[j - 1]) 
        cout << s1[i - 1];
}

int main(){
    input();
 
    for (int i = 1; i <= l1; i ++){
        for (int j = 1; j <= l2; j ++){
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }     
        }
    }

    cout << dp[l1][l2] << '\n';
    print(l1, l2);

}