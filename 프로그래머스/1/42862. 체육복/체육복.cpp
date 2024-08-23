#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> cnt(n + 1, 0);
    
    for (int l : lost) cnt[l]--;
    for (int r : reserve) cnt[r]++;
    
    for (int i = 1; i <= n; ++i){
        if (cnt[i] == -1){
            if (cnt[i - 1] == 1){
                cnt[i - 1] = 0;
                cnt[i] = 0;
            }
            else if (cnt[i + 1] == 1){
                cnt[i + 1] = 0;
                cnt[i] = 0;
            }
        }
        
        if (cnt[i] >= 0) ++answer;
    }
    
    return answer;
}