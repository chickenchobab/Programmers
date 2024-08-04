#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> edges[20002];
queue<pair<int, int>> q;
int maxDistance;
int distances[20002];

void bfs(){
    q.push({1, 0});
    distances[1] = -1;
    
    while (!q.empty()){
        auto [cur, dst] = q.front();
        q.pop();
        maxDistance = max(maxDistance, dst);
        
        for (auto &nxt : edges[cur]){
            if (distances[nxt]) continue;
            distances[nxt] = dst + 1;
            q.push({nxt, dst + 1});
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (auto &e : edge){
        edges[e[0]].push_back(e[1]);
        edges[e[1]].push_back(e[0]);
    }
    bfs();
    for (int i = 1; i <= n; ++i){
        if (maxDistance == distances[i]) ++answer;
    }
    return answer;
}