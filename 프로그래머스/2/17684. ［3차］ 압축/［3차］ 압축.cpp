#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dic;
    int idx = 0;
    for (char a = 'A'; a <= 'Z'; ++a){
        string str = "";
        dic[str + a] = ++idx;
    }
    
    int s, e;
        
    for (s = 0; s < msg.length(); ++s){
        for (e = s; e < msg.length() && dic[msg.substr(s, e - s + 1)]; ++e);
        answer.push_back(dic[msg.substr(s, e - s)]);
        dic[msg.substr(s, e - s + 1)] = ++idx;
        s = e - 1;
    }
    
    return answer;
}