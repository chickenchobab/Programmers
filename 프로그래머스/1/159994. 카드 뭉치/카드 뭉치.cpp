#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {

    int l = 0, r = 0;
    
    for (int i = 0; i < goal.size(); ++i){
        if (l < cards1.size() && cards1[l] == goal[i]) ++l;
        else if (r < cards2.size() && cards2[r] == goal[i]) ++r;
        else return "No";
    }
    
    return "Yes";
}