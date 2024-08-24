#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    char maxVal;
    for (int i = 0; i < number.size(); ++i){
        if (answer.size()) maxVal = max(answer.back(), number[i]);
        while (answer.size() && answer.back() < maxVal && k){
            k--;
            answer.pop_back();
        }
        answer.push_back(number[i]);
    }
    
    while (k--) answer.pop_back();
    return answer;
}