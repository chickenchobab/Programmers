#include <string>
#include <vector>
#include <iostream>

using namespace std;

int myKind, broKind;
int myCnt[10001], broCnt[10001];

int solution(vector<int> topping) {
    int answer = 0;
    for (int &t : topping){
        if (++broCnt[t] == 1) ++broKind;
    }
    for (int &t : topping){
        if (++myCnt[t] == 1) ++myKind;
        if (--broCnt[t] == 0) --broKind;
        if (myKind == broKind) ++answer;
    }
    return answer;
}