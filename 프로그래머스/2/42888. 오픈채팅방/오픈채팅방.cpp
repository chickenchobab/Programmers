#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> nicknames;
    
    for (int i = 0; i < record.size(); ++i){
        
        stringstream ss(record[i]);
        
        string action, uid;
        
        ss >> action >> uid;
        
        if (action == "Enter" || action == "Change"){
            string nickname;
            ss >> nickname;
            nicknames[uid] = nickname;
        }
        
        if (action == "Enter"){
            answer.push_back(uid + "님이 들어왔습니다.");
        }
        else if (action == "Leave"){
            answer.push_back(uid + "님이 나갔습니다.");
        }
    }
    
    for (int i = 0; i < answer.size(); ++i){
        int pos = answer[i].find("님");
        answer[i] = nicknames[answer[i].substr(0, pos)] + answer[i].substr(pos);
    }
    
    return answer;
    
}