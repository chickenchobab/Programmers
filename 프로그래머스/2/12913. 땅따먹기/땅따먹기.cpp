#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> findTwoCol(vector<vector<int>> &dp, int row){
    vector<pair<int, int>> tmp(4);
    for (int i = 0; i < 4; ++i){
        tmp[i] = {dp[row][i], i};
    }
    sort(tmp.rbegin(), tmp.rend());
    return {tmp[0].second, tmp[1].second};
}

int solution(vector<vector<int>> land)
{
    // int answer = 0;
    int N = land.size();
    vector<vector<int>> dp(N, vector<int>(4, 0));
    
    dp[0] = land[0];
    
    for (int i = 1; i < N; ++i){
        auto [fst, scn] = findTwoCol(dp, i - 1);
        for (int j = 0; j < 4; ++j){
            fst == j ? dp[i][j] = dp[i - 1][scn] : dp[i][j] = dp[i - 1][fst];
            dp[i][j] += land[i][j];
        }
    }
    
    return *(max_element(dp.back().begin(), dp.back().end()));
}