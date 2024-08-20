#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    //if (n == 3) return *max_element(money.begin(), money.end());
        
    vector<int> dp1(n), dp2(n);
    
    dp1[0] = money[0], dp1[1] = money[0], dp1[2] = money[0] + money[2];
    for (int i = 3; i < n; ++i){
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
    }
    dp2[0] = 0, dp2[1] = money[1], dp2[2] = max(money[1], money[2]);
    for (int i = 3; i < n; ++i){
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
    }
    
    
    
    return max(dp1[n - 2], dp2[n - 1]);
}