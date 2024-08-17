#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    answer[0] = ((brown + 4) / 2 + sqrt(pow(brown + 4, 2) / 4 - 4 * (brown + yellow))) / 2;
    answer[1] = (brown + yellow) / answer[0];
    return answer;
}