#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 3333333

using namespace std;

typedef pair<int, int> edge;
int n,e,s,a,b,c;
vector<edge> graph[22222];
priority_queue<edge, vector<edge>, greater<edge>> pq;
int d[22222];

int main(){
    cin>>n>>e>>s;
    for(int i=1;i<=e;i++){
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
        if(a==s) {pq.push({c,b}); d[b]=c;}
    }
    for(int i=1;i<=n;i++){
        if(i==s) {pq.push({0,i}); d[i]=0;}
        else {pq.push({INF,i}); d[i]=INF;}
    }

    while(!pq.empty()){
        edge u = pq.top();
        pq.pop();
        for(edge v:graph[u.second]){
            if(d[u.second]+v.first<d[v.second]){
                d[v.second]=d[u.second]+v.first;
                pq.push({d[v.second],v.second});
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(d[i]==INF) cout<<"INF";
        else cout<<d[i];
        cout<<'\n';
    }



    


}