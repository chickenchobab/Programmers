#include <string>
#include <vector>
#include <queue>
#define INF 222222222
using namespace std;

int N, S, A, B;
vector<pair<int, int>> edges[202];

typedef struct Element{
    int pos, dst;
}elm;
struct cmp{
    bool operator()(elm &a, elm &b){
        return a.dst > b.dst;
    }
};
priority_queue<elm, vector<elm>, cmp> pq;
vector<int> starts;
vector<int> distances[3];

void dijkstra(int s){
    int start = starts[s];
    distances[s].assign(N + 1, INF);
    
    pq.push({start, 0});
    distances[s][start] = 0;
    
    while (!pq.empty()){
        auto [cur, dst] = pq.top();
        pq.pop();
        
        if (distances[s][cur] < dst) continue;
        
        for (auto &e : edges[cur]){
            auto [nxt, dst] = e;
            if (distances[s][nxt] > distances[s][cur] + dst){
                distances[s][nxt] = distances[s][cur] + dst;
                pq.push({nxt, dst});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    N = n, S = s, A = a, B = b;
    starts.push_back(S);
    starts.push_back(A);
    starts.push_back(B);
    for (auto &e : fares){
        edges[e[0]].push_back({e[1], e[2]});
        edges[e[1]].push_back({e[0], e[2]});
    }
    
    
    for (int s = 0; s < 3; ++ s) 
        dijkstra(s);
    
    for (int i = 1; i <= n; ++i){
        answer = min(answer, distances[0][i] + distances[1][i] + distances[2][i]);
    }
    
    return answer;
}