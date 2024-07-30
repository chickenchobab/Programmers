#include<vector>
#include<queue>
using namespace std;

int n, m;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

int bfs(vector<vector<int>> &maps){
    queue<pair<int, int>> q;
    int visited[100][100] = {0,};
    
    q.push({0, 0});
    visited[0][0] = 1;
    
    while (q.size()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        
        if (i == n - 1 && j == m - 1) return visited[i][j];
        
        for (int d = 0; d < 4; ++d){
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (visited[ni][nj] || maps[ni][nj] == 0) continue;
            q.push({ni, nj});
            visited[ni][nj] = visited[i][j] + 1;
        }
        
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    
    
    return bfs(maps);
}