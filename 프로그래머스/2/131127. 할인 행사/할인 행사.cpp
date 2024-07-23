#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    int done = 0;
    unordered_map<string, int> wantIdx;
    unordered_map<string, int> count;
    
    for (int i = 0; i < want.size(); ++i){
        wantIdx[want[i]] = i + 1;
    }
    
    for (int i = 0; i < 10; ++i){
        count[discount[i]]++;
        if (wantIdx[discount[i]] && count[discount[i]] == number[wantIdx[discount[i]] - 1]) ++done;
    }
    
    if (done == want.size()) ++answer;
    
    
    for (int i = 10; i < discount.size(); ++i){
        if (wantIdx[discount[i - 10]] && count[discount[i - 10]] == number[wantIdx[discount[i - 10]] - 1]) --done;
        count[discount[i - 10]]--;
        
        count[discount[i]]++;
        if (wantIdx[discount[i]] && count[discount[i]] == number[wantIdx[discount[i]] - 1]) ++done;
        if (done == want.size()) ++answer;
        
    }
    
    return answer;
}