#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct NODE{
    int x, wolf, sheep, visit;
}node;
queue<node> q;
vector<vector<int>> graph;
vector<vector<bool>> visited;
int answer;

void bfs(vector<int> &info){
    q.push({0, info[0], !info[0], 1 << (0 + 1)});
    
    while (q.size()){
        int cur = q.front().x;
        int wolf = q.front().wolf;
        int sheep = q.front().sheep;
        int visit = q.front().visit;
        q.pop();
        
        answer = max(answer, sheep);
        
        for (int nxt : graph[cur]){
            if ((visit & (1 << (nxt + 1))) == 0 && info[nxt] + wolf >= !info[nxt] + sheep) continue;
            if (visited[nxt][visit | (1 << (nxt + 1))]) continue;
            visited[nxt][visit | (1 << (nxt + 1))] = 1;
            if (visit & (1 << (nxt + 1))) 
                q.push({nxt, wolf, sheep, visit});
            else
                q.push({nxt, wolf + info[nxt], sheep + !info[nxt], visit | (1 << (nxt + 1))});
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {

    graph.resize(info.size());
    visited.assign(info.size(), vector<bool>(1 << (info.size() + 1)));
    for (auto edge : edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    bfs(info);
    return answer;
}