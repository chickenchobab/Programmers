#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    unordered_map<string, int> idToNum;
    vector<int> edges[id_list.size()];
    vector<int> inDegree(id_list.size(), 0), answer(id_list.size(), 0);
    
    
    for (int i = 0; i < id_list.size(); ++ i){
        idToNum[id_list[i]] = i;
    }
    
    for (int i = 0; i < report.size(); ++i){
       for (int j = 0; j < report[i].size(); ++j){
           if (report[i][j] == ' '){
               int from = idToNum[report[i].substr(0, j)];
               int to = idToNum[report[i].substr(j + 1)];
               if (find(edges[to].begin(), edges[to].end(), from) != edges[to].end()) break;
               edges[to].push_back(from);
               inDegree[to]++;
               break;
           }
       }
    }
    
    for (int i = 0; i < id_list.size(); ++i){
        if (inDegree[i] >= k){
            for (int j : edges[i]) answer[j]++;
        }
    }
    
    return answer;
}