#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF (700 * 25 * 25)

using namespace std;

typedef struct NODE{
    int i, j, dst, dir;
}node;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
struct cmp{
    bool operator()(node &a, node &b){
        return a.dst < b.dst;
    }
};
vector<vector<vector<int>>> distances;
priority_queue<node, vector<node>, cmp> pq;

void dijkstra(vector<vector<int>> &board){
    distances[0][0][0] = distances[0][0][1] = distances[0][0][2] = distances[0][0][3] = 0;
    if (!board[1][0]){
        pq.push({1, 0, 100, 0});
        distances[1][0][0] = 100;
    }
    if (!board[0][1]){
        pq.push({0, 1, 100, 2});
        distances[0][1][2] = 100;
    }
    
    while (pq.size()){
        auto [i, j, dst, dir] = pq.top();
        pq.pop();
        
        // if (distances[i][j] < dst) continue;
        
        for (int newdir = 0; newdir < 4; ++newdir){
            int ni = i + di[newdir];
            int nj = j + dj[newdir];
            if (ni < 0 || ni >= board.size() || nj < 0 || nj >= board.size()) continue;
            if (board[ni][nj]) continue;
            
            if (distances[ni][nj][newdir] >= distances[i][j][dir] + 100 + 500 * (dir / 2 != newdir / 2)){
                distances[ni][nj][newdir] = distances[i][j][dir] + 100 + 500 * (dir / 2 != newdir / 2);
                pq.push({ni, nj, distances[ni][nj][newdir], newdir});
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = INF;
    distances.resize(board.size(), vector<vector<int>>(board.size(), vector<int>(4, INF)));
    dijkstra(board);
    for (int d = 0; d < 4; ++d){
        answer = min(answer, distances[board.size() - 1][board.size() - 1][d]);
    }
    return answer;
}