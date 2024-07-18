#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    set<int> s;
    
    int numCnt = numbers.size();
    for (int i = 0; i < numCnt; ++i){
        for (int j = i + 1; j < numCnt; ++j){
            s.insert(numbers[i] + numbers[j]);
        }
    }
    vector<int> answer(s.begin(), s.end());
    return answer;
}