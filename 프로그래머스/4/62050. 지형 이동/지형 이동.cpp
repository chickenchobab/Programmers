#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std; 
int N, H;
queue<pair<int, int>> q;
vector<vector<int>> component;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
vector<tuple<int, int, int>> edges;
vector<int> parent;

void bfs(vector<vector<int>> &land, int i, int j, int idx){
    q.push({i, j});
    component[i][j] = idx;
    
    while (q.size()){
        auto [i, j] = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; ++dir){
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
            if (component[ni][nj] == idx) continue;
            
            if (component[ni][nj] != -1){
                int diff = abs(land[ni][nj] - land[i][j]);
                edges.push_back({diff, component[ni][nj], idx});
                edges.push_back({diff, idx, component[ni][nj]});
            }
            else if (abs(land[ni][nj] - land[i][j]) <= H){
                component[ni][nj] = idx;
                q.push({ni, nj});
            }
        }
    }
}

int find(int x){
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    
    if (parent[a] < parent[b])
        parent[b] = a;
    else {
        if (parent[a] == parent[b])
            parent[b]--;
        parent[a] = b;
    }
}

int makeMST(int idx){
    int ret = 0;
    
    parent.assign(idx + 1, -1);
    sort(edges.begin(), edges.end());
    
    for (auto e : edges){
        auto [d, a, b] = e;
        if (find(a) == find(b)) continue;
        ret += d;
        merge(a, b);
    }
    
    return ret;
}

int solution(vector<vector<int>> land, int height) {
    N = land.size();
    H = height;
    component.assign(N, vector<int>(N, -1));
    
    int idx = -1;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if (component[i][j] != -1) continue;
            bfs(land, i, j, ++idx);
        }
    }
    
    return makeMST(idx);
}