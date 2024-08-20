#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 22222
using namespace std;

int solution(vector<string> strs, string t)
{    
    vector<int> dp(t.length() + 1, MAX);
    
    sort(strs.begin(), strs.end(), [](string &a, string &b){
        return a.length() < b.length();
    });
    
    dp[0] = 0;
    int i, j;
    for (i = 1; i <= t.length(); ++i){
        for (string &str : strs){
            if (str.length() > i) break;
            // if (str == t.substr(i - str.size(), str.size())){
            // 	dp[i] = min(dp[i], dp[i - str.size()] + 1);
            // }
            int idx = i - str.size();
            for (j = 0; j < str.length() && str[j] == t[idx + j]; ++j);
            if (j == str.length())
                dp[i] = min(dp[i], dp[i - str.size()] + 1);
        }
    }
    
    return dp[t.length()] == MAX ? -1 : dp[t.length()];
}