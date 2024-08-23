#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int range = 2 * w + 1;
    
    int space = max(0, stations[0] - w - 1);
    if (space) answer += space / range + (bool)(space % range);
    space = max(0, n - (stations[stations.size() - 1] + w + 1) + 1);
    if (space) answer += space / range + (bool)(space % range);
    
    for (int i = 0; i < stations.size() - 1; ++i){
        if ((space = stations[i + 1] - stations[i] - range) <= 0) continue;
        answer += space / range + (bool)(space % range);
    }
    
    return answer;
}