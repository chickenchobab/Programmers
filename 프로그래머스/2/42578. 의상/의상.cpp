#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> clothTypeNum;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for (int i = 0; i < clothes.size(); ++i){
        clothTypeNum[clothes[i][1]]++;
    }
    for (auto clothType : clothTypeNum){
        answer *= (clothType.second + 1);
    }
    return answer - 1;
}