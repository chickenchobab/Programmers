#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int s = 0, e = people.size() - 1;
    while (s < e){
        if (people[e] + people[s] <= limit){
            --e;
            ++s;
            ++answer;
        }
        else if (people[e] <= limit){
            --e;
            ++answer;
        }
    }
    if (s == e) ++answer;
    return answer;
}