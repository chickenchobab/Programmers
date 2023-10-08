#include <iostream>
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
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>e>>s;
    for(int i=1;i<=e;i++){
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
    }
    
    //모든 노드 정보를 pq에 넣음
    for(int i=1;i<=n;i++){
        if(i==s) {pq.push({0,i}); d[i]=0;}
        else {pq.push({INF,i}); d[i]=INF;}
    }

    //d가 작은 노드부터 처리되므로
    //d가 무한대라면 이미 갱신된 이후에나 등장함
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