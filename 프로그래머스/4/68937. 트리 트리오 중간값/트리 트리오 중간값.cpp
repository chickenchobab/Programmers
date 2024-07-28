#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> graph;
int diameter, point, points[2];
int fstDist, scnDist;

void findDiameter(int cur, int prv, int cnt){

    if (diameter <= cnt){
        diameter = cnt;
        points[point] = cur;
    }
    
    for (int &nxt : graph[cur]){
        if (nxt == prv) continue;
        findDiameter(nxt, cur, cnt + 1);
    }
}

void getDistances(int cur, int prv, int cnt){
    if (cnt > fstDist){
        scnDist = fstDist;
        fstDist = cnt;
    }
    else if (cnt > scnDist)
        scnDist = cnt;
    
    for (int &nxt : graph[cur]){
        if (nxt == prv) continue;
        getDistances(nxt, cur, cnt + 1);
    }
}

int solution(int n, vector<vector<int>> edges) {
    graph.resize(n + 1);
    for (auto &edge : edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    findDiameter(1, 0, 0);
    ++point;
    findDiameter(points[0], 0, 0);
    
    getDistances(points[0], 0, 0);
    int tmp = scnDist;
    fstDist = 0, scnDist = 0;
    getDistances(points[1], 0, 0);
    
    return max(tmp, scnDist);
}