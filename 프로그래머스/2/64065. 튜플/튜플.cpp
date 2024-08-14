#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> counts(100001, 0);
    vector<int> numbers;
    
    string numStr = "";
    for (char &ch : s){
        if (isdigit(ch)) {
            numStr += ch;
        }
        else {
            if (numStr.empty()) continue;
            int num = stoi(numStr);
            if (!counts[num]) numbers.push_back(num);
            counts[num]++;
            numStr.clear(); 
        }
    }
    
    sort(numbers.begin(), numbers.end(), [counts](int &a, int &b){
        return counts[a] > counts[b];
    });
    return numbers;
}