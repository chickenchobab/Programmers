#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer;
vector<int> ryan(11, 0);
int maxScoreGap;

void shootArrow(vector<int> &apeach, int target, int arrow, int ryanScore, int apeachScore){
    if (target == -1){
        if (ryanScore - apeachScore > maxScoreGap){
            maxScoreGap = ryanScore - apeachScore;
            ryan.back() = arrow;
            answer = ryan;
        }
        return;
    }
    
    // win this stage
    if (arrow > apeach[target]){
        ryan[target] = apeach[target] + 1;
        shootArrow(apeach, target - 1, arrow - apeach[target] - 1, ryanScore + 10 - target, apeachScore);
        ryan[target] = 0;
    }
    
    // do not shoot
    shootArrow(apeach, target - 1, arrow, ryanScore, apeachScore + (10 - target) * (bool)apeach[target]);
}

vector<int> solution(int n, vector<int> info) {
    shootArrow(info, 10, n, 0, 0);
    if (!maxScoreGap) 
        answer.push_back(-1);
    return answer;
}