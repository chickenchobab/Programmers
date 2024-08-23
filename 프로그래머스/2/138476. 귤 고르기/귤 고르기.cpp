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
    vector<pair<int, int>> counts(count.begin(), count.end());
    sort(counts.begin(), counts.end(), [](auto &a, auto &b){
        return a.second > b.second;
    });
    for (int i = 0; i < counts.size(); ++i){
        k -= min(k, counts[i].second);
        if (!k) return i + 1;
    }
    return counts.size();
}