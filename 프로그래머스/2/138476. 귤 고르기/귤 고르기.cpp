#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> count;
    
    for (int &t : tangerine){
        ++count[t];
    }
    vector<int> counts;
    for (auto &p : count){
        counts.push_back(p.second);
    }
    sort(counts.rbegin(), counts.rend());
    for (int i = 0; i < counts.size(); ++i){
        k -= min(k, counts[i]);
        if (!k) return i + 1;
    }
    return counts.size();
}