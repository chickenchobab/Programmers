#include <iostream>
#include <vector>
#include <queue>
#define INF 555555
using namespace std;

typedef pair<int, int> pr;
priority_queue<pr, vector<pr>, greater<pr>> pq;
vector<vector<pr>> edges;
vector<int> dst;

void dijkstra(){
    dst[1] = 0;
    pq.push({0, 1});
    
    while (pq.size()){
        auto [wgh, cur] = pq.top();
        pq.pop();
        
        if (dst[cur] < wgh) continue;
        
        for (auto edge : edges[cur]){
            auto [wgh, nxt] = edge;
            if (dst[nxt] > dst[cur] + wgh){
                dst[nxt] = dst[cur] + wgh;
                pq.push({dst[nxt], nxt});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    
    edges.resize(N + 1);
    for (auto edge : road){
        edges[edge[0]].push_back({edge[2], edge[1]});
        edges[edge[1]].push_back({edge[2], edge[0]});
    }
    
    dst.resize(N + 1, INF);
    dijkstra();
    
    for (int &d : dst){
        if (d <= K) ++answer;
    }
    return answer;
}