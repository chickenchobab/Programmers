#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> edges[101][2];
vector<bool> visited;
bool isReversed;

int cntChildren(int cur){
    int ret = 0;
    visited[cur] = 1;
    for (int nxt : edges[cur][isReversed]){
        if (visited[nxt]) continue;
        ret += cntChildren(nxt);
    }
    return ret + 1;
}

void show(){
    for (int i : visited){
        cout << i << ' ';
    }
    cout << endl;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (auto &e : results) {
        edges[e[0]][0].push_back(e[1]);
        edges[e[1]][1].push_back(e[0]);
    }
    
    visited.resize(n + 1, 0);
    int winner = 0, loser = 0;
    for (int i = 1; i <= n; ++i){
        isReversed = 0;
        visited.assign(n + 1, 0);
        winner = cntChildren(i) - 1;
        isReversed = 1;
        visited.assign(n + 1, 0);
        loser = cntChildren(i) - 1;
        if (winner + loser == n - 1) ++answer;
    }
    
    return answer;
}