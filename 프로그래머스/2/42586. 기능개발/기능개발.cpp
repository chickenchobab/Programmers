#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int, int>> q;
    
    for (int i = 0; i < progresses.size(); ++i){
        q.push({progresses[i], i});
    }
    
    int prv = 0, cur = 0;
    for (int i = 0; i < progresses.size(); ++i){
        
        while (!(q.front().second == i && q.front().first >= 100)){
            q.push({q.front().first + speeds[q.front().second], q.front().second});
            q.pop();
            cur ++;
        }
        q.pop();
        
        if (cur == prv) answer.back()++;
        else answer.push_back(1);
        prv = cur;
    }
    
    return answer;
}