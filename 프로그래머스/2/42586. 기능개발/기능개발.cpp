#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int day = 0;
    int maxDay = 0;
    for (int i = 0; i < progresses.size(); ++i){
        
        day = ceil((100.0 - progresses[i]) / speeds[i]);
        if (maxDay < day) answer.push_back(1);
        else answer.back()++;
        
        maxDay = max(maxDay, day);
    }
    
    return answer;
}