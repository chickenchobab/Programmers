#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> q1, q2;
    
    for (int i = 0; i < cards1.size(); ++i) q1.push(cards1[i]);
    for (int i = 0; i < cards2.size(); ++i) q2.push(cards2[i]);
    
    answer = "Yes";
    
    for (int i = 0; i < goal.size(); ++i){
        if (q1.size() && goal[i] == q1.front()) q1.pop();
        else if (q2.size() && goal[i] == q2.front()) q2.pop();
        else {
            answer = "No";
            break;
        }
    }
    
    return answer;
}