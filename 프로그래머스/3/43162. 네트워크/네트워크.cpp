#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

void dfs(vector<vector<int>> &computers, int cur){
    visited[cur] = 1;
    for (int nxt = 0; nxt < computers.size(); ++nxt){
        if (!computers[cur][nxt]) continue;
        if (visited[nxt]) continue;
        dfs(computers, nxt);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.resize(n, 0);
    
    for (int i = 0; i < n; ++i){
        if (visited[i]) continue;
        ++answer;
        dfs(computers, i);
    }
    
    return answer;
}