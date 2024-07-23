#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, bool> isSaid;
    
    isSaid[words[0]] = 1;
    for (int i = 1; i < words.size(); ++i){
        if (isSaid[words[i]] || words[i][0] != words[i - 1].back()) {
            return answer = {i % n + 1, i / n + 1};
        }
        isSaid[words[i]] = 1;
    }

    return answer = {0, 0};
}