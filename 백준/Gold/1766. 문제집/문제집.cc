#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

//typedef priority_queue<int, vector<int>, greater<int>> heap;
int n,m,a,b;
vector<int> graph[33333];
priority_queue<int, vector<int>, greater<int>> pq;
int ind[33333];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        graph[a].push_back(b);
        ind[b]++;
    }

    for(int i=1;i<=n;i++){
        if(ind[i]==0) pq.push(i);    
        sort(graph[i].begin(), graph[i].end());
    }
    while(!pq.empty()){
        int u=pq.top();
        pq.pop();
        cout<<u<<' ';
        for(int v:graph[u]){
            if(--ind[v]==0) pq.push(v);
        }
    }
}