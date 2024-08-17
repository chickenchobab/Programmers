#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);

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
    answer[0]++;
    answer[1] += cnt;
    s = decToBin(len - cnt);
}

vector<int> solution(string s) {
    while (s.length() != 1){
        binaryTransform(s);
    }
    return answer;
}