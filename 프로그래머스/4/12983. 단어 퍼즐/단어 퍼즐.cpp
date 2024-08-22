#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#define MAX 22222
using namespace std;

int solution(vector<string> strs, string t)
{    
    unordered_set<string> strsSet(strs.begin(), strs.end());
    unordered_set<int> sizes;
    for (const auto &s : strs)
        sizes.insert(s.length());
    vector<int> dp(t.length() + 1, MAX);
    
    
    dp[0] = 0;
    for (int i = 1; i <= t.length(); ++i){
        for (int size : sizes){
            if (i >= size && strsSet.count(t.substr(i - size, size)))
                dp[i] = min(dp[i], dp[i - size] + 1);
        }
    }
    
    return dp[t.length()] == MAX ? -1 : dp[t.length()];
}