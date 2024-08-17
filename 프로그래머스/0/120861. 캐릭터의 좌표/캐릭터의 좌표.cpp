#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    int n = board[0] / 2, m = board[1] / 2;
    int i = 0, j = 0;
    for (auto &k : keyinput){
        if (k == "left") i = max(-n, i - 1);
        else if (k == "right") i = min(n, i + 1);
        else if (k == "up") j = min(m, j + 1);
        else j = max(-m, j - 1);
    }
    return vector<int> {i, j};
}