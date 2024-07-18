#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt = answers.size();
    
    vector<int> pick[3] = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    vector<int> mod = {5, 8, 10};
    vector<int> grade(3, 0);
    
    for (int i = 0; i < cnt; ++i){
        for (int j = 0; j < 3; ++j){
            if (pick[j][i % mod[j]] == answers[i]){
                grade[j] ++;
            }
        }
    }
    
    int maxGrade = 0;
    for (int i = 0; i < 3; ++i){
        maxGrade = max(maxGrade, grade[i]);
    }
    for (int i = 0; i < 3; ++i){
        if (grade[i] == maxGrade)
            answer.push_back(i + 1);
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}