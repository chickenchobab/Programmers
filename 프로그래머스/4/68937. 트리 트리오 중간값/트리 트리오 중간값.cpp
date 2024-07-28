#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> graph;
int point, diameter, diameterCnt;


void findDiameter(int cur, int prv, int cnt){

    if (diameter <= cnt){    
        diameter = cnt;
        ++diameterCnt;
        point = cur;
    }
    
    for (int &nxt : graph[cur]){
        if (nxt == prv) continue;
        findDiameter(nxt, cur, cnt + 1);
    }
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    
    graph.resize(n + 1);
    for (auto &edge : edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    int p1, p2;
    findDiameter(1, 0, 0);
    p1 = point;
    findDiameter(point, 0, 0);
    p2 = point;
    
    diameterCnt = 0;
    findDiameter(p1, 0, 0);
    diameterCnt == 1 ? answer = max(answer, diameter - 1) : answer = max(answer, diameter);
    diameterCnt = 0;
    findDiameter(p2, 0, 0);
    diameterCnt == 1 ? answer = max(answer, diameter - 1) : answer = max(answer, diameter);
    
    return answer;
}