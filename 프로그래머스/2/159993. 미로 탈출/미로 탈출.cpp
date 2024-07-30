#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
typedef pair<int, int> pr;

int bfs(vector<string> &maps, pr &start, pr &end){
    queue<pair<int, int>> q;
    int visited[100][100] = {0,};
    
    q.push(start);
    visited[start.first][start.second] = 1;
    
    while (q.size()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        
        if (i == end.first && j == end.second) 
            return visited[i][j] - 1;
        
        for (int d = 0; d < 4; ++d){
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
            if (visited[ni][nj] || maps[ni][nj] == 'X') continue;
            q.push({ni, nj});
            visited[ni][nj] = visited[i][j] + 1;
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    N = maps.size();
    M = maps[0].size();
    
    int a, b;
    pr start, end, lever;
    
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            if (maps[i][j] == 'S') start = {i, j};
            else if (maps[i][j] == 'E') end = {i, j};
            else if (maps[i][j] == 'L') lever = {i, j};
        }
    }
    
    a = bfs(maps, start, lever);
    b = bfs(maps, lever, end);
    
    if (a == -1 || b == -1) return -1;
    else return a + b;
}