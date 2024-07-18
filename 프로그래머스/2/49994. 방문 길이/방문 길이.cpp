#include <string>
#include <unordered_map>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    set<pair<int, int>> visited;
    int i = 5, j = 5;
    unordered_map<char, int> dir = {{'L', 0}, {'R', 1}, {'U', 2}, {'D', 3}};
    int di[] = {0, 0, -1, 1}, dj[] = {-1, 1, 0, 0};
    
    for (const char &ch : dirs){
        int ni = i + di[dir[ch]];
        int nj = j + dj[dir[ch]];
        if (ni < 0 || ni > 10 || nj < 0 || nj > 10) continue;
        int idx1 = i * 11 + j;
        int idx2 = ni * 11 + nj;
        if (idx1 > idx2) swap(idx1, idx2);
        visited.insert({idx1, idx2});
        i = ni, j = nj;
    }
    answer = visited.size();
    
    
    
    return answer;
}