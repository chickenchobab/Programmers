#include <string>
#include <vector>

using namespace std;

int answer, targetNum;
vector<int> arr;

void dfs(int cur, int num){
    if (cur == arr.size() - 1){
        if (num == targetNum) ++answer;
    }
    else {
        dfs(cur + 1, num + arr[cur + 1]);
        dfs(cur + 1, num - arr[cur + 1]);
    }
}

int solution(vector<int> numbers, int target) {
    arr = numbers;
    targetNum = target;
    dfs(-1, 0);
    return answer;
}