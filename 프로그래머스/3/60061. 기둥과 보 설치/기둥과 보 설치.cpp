#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<pair<int, int>, bool> structure[2]; 

bool canBuildBeam(int x, int y){
    if (structure[0][{x, y - 1}] || structure[0][{x + 1, y - 1}]) return true;
    return (structure[1][{x - 1, y}] && structure[1][{x + 1, y}]);
}
bool canBuildPillar(int x, int y){
    if (!y) return true;
    return (structure[0][{x, y - 1}] || structure[1][{x - 1, y}] || structure[1][{x, y}]);
}

bool canRemoveBeam(int x, int y){
    bool ret = true;
    structure[1][{x, y}] = 0;
    if (structure[1][{x - 1, y}] && !canBuildBeam(x - 1, y)) ret = false;
    else if (structure[1][{x + 1, y}] && !canBuildBeam(x + 1, y)) ret = false;
    else if (structure[0][{x, y}] && !canBuildPillar(x, y)) ret = false;
    else if (structure[0][{x + 1, y}] && !canBuildPillar(x + 1, y)) ret = false;
    structure[1][{x, y}] = 1;
    return ret;
}

bool canRemovePillar(int x, int y){
    bool ret = true;
    structure[0][{x, y}] = 0;
    if (structure[1][{x, y + 1}] && !canBuildBeam(x, y + 1)) ret = false;
    else if (structure[1][{x - 1, y + 1}] && !canBuildBeam(x - 1, y + 1)) ret = false;
    else if (structure[0][{x, y + 1}] && !canBuildPillar(x, y + 1)) ret = false;
    structure[0][{x, y}] = 1;
    return ret;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for (auto &info : build_frame){
        if (info[2]){ // beam
            if (info[3] && canBuildBeam(info[0], info[1])) 
                structure[info[2]][{info[0], info[1]}] = 1;
            else if (!info[3] && canRemoveBeam(info[0], info[1]))
                structure[info[2]][{info[0], info[1]}] = 0;    
        }
        else { // pillar
            if (info[3] && canBuildPillar(info[0], info[1])) 
                structure[info[2]][{info[0], info[1]}] = 1;
            else if (!info[3] && canRemovePillar(info[0], info[1]))
                structure[info[2]][{info[0], info[1]}] = 0; 
        }
    }
    for (int s = 0; s < 2; ++s){
        for (auto it = structure[s].begin(); it != structure[s].end(); ++it){
            if ((*it).second == 0) continue;
            answer.push_back(vector<int>{(*it).first.first, (*it).first.second, s});
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}