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
    }
    
    for (int i = 0; i < record.size(); ++i){
        
        stringstream ss(record[i]);
        
        string action, uid;
        ss >> action >> uid;
        
        if (action == "Enter"){
            answer.push_back(nicknames[uid] + "님이 들어왔습니다.");
        }
        else if (action == "Leave"){
            answer.push_back(nicknames[uid] + "님이 나갔습니다.");
        }
    }
    
    return answer;
    
}