#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), [](auto &a, auto &b){
        return a[1] < b[1];
    });
    
    ++answer;
    int recentPos = routes[0][1];
    for (int i = 1; i < routes.size(); ++i){
        if (recentPos >= routes[i][0]) {
            continue;
        }
        ++answer;
        recentPos = routes[i][1];
    }
        
    return answer;
}