#include <iostream>
#include <vector>
#include <queue>
#define MAX 200000000

using namespace std;

int n,e,a,b,c,x,y,ans;
typedef pair<int,int> p;
vector<p> g[808];


int dijkstra(int start, int end){
    priority_queue<p, vector<p>, greater<p>> pq;
    int d[808];

    for(int i=1;i<=n;i++){
        d[i]=MAX;
    }d[start]=0;

    pq.push({0, start});

    while(pq.size()){
        p u = pq.top();
        pq.pop();

        if(d[u.second]<u.first) continue;

        for(p v:g[u.second]){
            int uv=v.first;
            if(d[v.second]>uv+d[u.second]) {
                d[v.second]=uv+d[u.second];
                pq.push({d[v.second], v.second});
            }
        }
    }
    return d[end];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>e;

    for(int i=1;i<=e;i++){
        cin>>a>>b>>c;
        g[a].push_back({c,b});
        g[b].push_back({c,a});
    }

    cin>>x>>y;

    //dijkstra(0,1); dijkstra(1,x); dijkstra(2,y);
    ans=MAX;
    ans=min(ans,dijkstra(1,x)+dijkstra(x,y)+dijkstra(y,n));
    ans=min(ans,dijkstra(1,y)+dijkstra(y,x)+dijkstra(x,n));
    

    cout<<((ans<MAX)? ans:-1);
    
    
}