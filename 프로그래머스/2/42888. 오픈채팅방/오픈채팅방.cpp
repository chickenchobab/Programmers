#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> nickname;
    
    for (int i = 0; i < record.size(); ++i){
        
        stringstream ss(record[i]);
        vector<string> tokens;
        string token;
        while (ss >> token){
            tokens.push_back(token);
        }
        
        if (tokens[0] == "Enter"){
            answer.push_back(tokens[1] + "님이 들어왔습니다.");
            nickname[tokens[1]] = tokens[2];
        }
        else if (tokens[0] == "Leave"){
            answer.push_back(tokens[1] + "님이 나갔습니다.");
        }
        else {
            nickname[tokens[1]] = tokens[2];
        }
    }
    
    for (int i = 0; i < answer.size(); ++i){
        int pos = answer[i].find("님");
        answer[i] = nickname[answer[i].substr(0, pos)] + answer[i].substr(pos);
    }
    
    return answer;
    
}