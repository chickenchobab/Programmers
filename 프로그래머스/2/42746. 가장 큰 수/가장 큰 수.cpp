#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;
    for (int &num : numbers){
        strings.push_back(to_string(num));
    }
    sort(strings.begin(), strings.end(), [](string &a, string &b){
        return (a + b) > (b + a);
    });
    for (auto &s : strings){
        answer += s;
    }
    return answer[0] == '0' ? "0" : answer;
}