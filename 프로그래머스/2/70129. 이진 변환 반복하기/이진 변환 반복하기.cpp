#include <string>
#include <vector>

using namespace std;

int transCnt, zeroCnt;

string decToBin(int num){
    string s = "";
    while (num){
        char digit = num % 2 + '0';
        s = digit + s;
        num /= 2;
    }
    return s;
}

void binaryTransform(string &s){
    int len = s.length();
    int cnt = 0;
    for (char &ch : s){
        if (ch == '0') ++cnt;
    }
    ++transCnt;
    zeroCnt += cnt;
    s = decToBin(len - cnt);
}

vector<int> solution(string s) {
    vector<int> answer;
    while (s.length() != 1){
        binaryTransform(s);
    }
    answer.push_back(transCnt);
    answer.push_back(zeroCnt);
    return answer;
}