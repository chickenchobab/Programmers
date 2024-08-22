#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_set<int> dp[9];

int solution(int N, int number) {
    
    int answer = 9;
    int num = 0;
    for (int i = 1; i <= 8; ++i){
        num *= 10;
        num += N;
        dp[i].insert(num);
    }
    
    for (int cnt = 1; cnt <= 8; ++cnt){
        for (int i = 1; i < cnt; ++i){
            int j = cnt - i;
            
            for (int a : dp[i]){
                for (int b : dp[j]){
                    dp[cnt].insert(a + b);
                    if (a > b) dp[cnt].insert(a - b);
                    dp[cnt].insert(a * b);
                    if (b) dp[cnt].insert(a / b);
                }
            }      
        } 
    }
    
    for (int cnt = 1; cnt <= 8; ++cnt){
        if (dp[cnt].count(number)) return cnt;
    }
    return -1;
}