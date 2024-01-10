#include <iostream>
#include <vector>

using namespace std;

int n,m,cnt=0;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int u)
{
    visited[u]=++cnt;

    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(!visited[v]) 
            dfs(graph, visited, v);
    }
}

int main(){

    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    vector<int> visited(n+1,0);

    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(graph, visited,1);
    cout<<cnt-1;

}