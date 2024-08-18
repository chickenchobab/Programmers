#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int solution(string name) {
    int len = name.size();
    int changeCnt = 0, moveCnt = len - 1;
    
    for (char &c : name){
        changeCnt += min(c - 'A', 26 - (c - 'A'));
    }
    for (int cur = 0; cur < len; ++cur){
        int nxt = cur + 1;
        while (nxt < len && name[nxt] == 'A'){
            ++nxt;
        }
        moveCnt = min(moveCnt, cur + 2 * (len - nxt));
        moveCnt = min(moveCnt, 2 * cur + (len - nxt));
    }
    
    return changeCnt + moveCnt;
}