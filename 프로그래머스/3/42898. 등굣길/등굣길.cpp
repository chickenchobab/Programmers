#include <string>
#include <vector>
#define MAX 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (auto &p : puddles){
        dp[p[0]][p[1]] = MAX;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            if (dp[i][j] == MAX) continue;
            dp[i][j] = (dp[i][j] + (dp[i - 1][j] == MAX ? 0 : dp[i - 1][j])) % MAX;
            dp[i][j] = (dp[i][j] + (dp[i][j - 1] == MAX ? 0 : dp[i][j - 1])) % MAX;
        }
    }
    return dp[m][n];
}