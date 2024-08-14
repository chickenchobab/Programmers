#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> counts(10001, 0);
    for (auto &c : citations){
        counts[c]++;
    }
    for (int i = 1; i <= 10000; ++i){
        counts[i] += counts[i - 1];
    }
    for (int h = 10000; h >= 1; --h){
        if (counts[10000] - counts[h - 1] >= h){
            answer = max(answer, h);
        }
    }
    return answer;
}