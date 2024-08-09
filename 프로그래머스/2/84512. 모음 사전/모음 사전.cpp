#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer, cnt;
string str, goal;
char alpha[5] = {'A', 'E', 'I', 'O', 'U'};

void getNextString(int len){
    ++cnt;
    if (str == goal){
        answer = cnt;
        return;
    }
    if (len == 5) return;
    
    for (int i = 0; i < 5; ++i){
        str.push_back(alpha[i]);
        getNextString(len + 1);
        str.pop_back();
    }
}

int solution(string word) {
    goal = word;
    cnt = -1;
    getNextString(0);
    return answer;
}