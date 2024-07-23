#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    // string answer = "";
    unordered_map<string, int> isComplete;
    
    for (int i = 0; i < completion.size(); ++i){
        isComplete[completion[i]]++;
    }
    for (int i = 0; i < participant.size(); ++i){
        isComplete[participant[i]]--;
    }
    for (int i = 0; i < participant.size(); ++i){
        if (isComplete[participant[i]] < 0) return participant[i];
    }
}