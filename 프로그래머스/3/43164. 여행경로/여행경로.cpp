#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int N;
unordered_map<string, deque<string>> edges;
unordered_map<string, int> useCnt, cnt;
vector<string> answer;
bool isDone;

void dfs(string cur){
    bool isLast = 1;
    
    for (auto &nxt : edges[cur]){
        if (useCnt[cur + nxt] == cnt[cur + nxt]) continue;
        isLast = 0;
        
        useCnt[cur + nxt]++;
        answer.push_back(nxt);
        dfs(nxt);
        if (isDone) return;
        useCnt[cur + nxt]--;
        answer.pop_back();
    }
    if (isLast && answer.size() == N) {
        isDone = 1;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    N = tickets.size() + 1;
    
    for (auto &t : tickets){
        cnt[t[0] + t[1]]++;
    }
    
    sort(tickets.begin(), tickets.end(), 
    [](vector<string> &a, vector<string> &b){
        return a[1] < b[1];
    });
    for (auto &edge : tickets){
        edges[edge[0]].push_back(edge[1]);
    }
    
    answer.push_back("ICN");
    dfs("ICN");
    
    return answer;
}