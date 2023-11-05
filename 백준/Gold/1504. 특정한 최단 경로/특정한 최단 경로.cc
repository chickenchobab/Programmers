#include <iostream>
#include <vector>
#include <queue>
#define MAX 200000000

using namespace std;

int n,e,a,b,c,x,y,ans;
typedef pair<int,int> p;
vector<p> g[808];

int shortest_distance(int start, int end){
    priority_queue<p> pq;
    int d[808];
    for(int i=1;i<=n;i++){
        if(i==start) d[i]=0;
        else d[i]=MAX;
        pq.push({d[i],i});
    }
    while(pq.size()){
        p u = pq.top();
        pq.pop();
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
    cin>>n>>e;

    for(int i=1;i<=e;i++){
        cin>>a>>b>>c;
        g[a].push_back({c,b});
        g[b].push_back({c,a});
    }

    cin>>x>>y;

    int d1x=shortest_distance(1,x);
    int d1y=shortest_distance(1,y);
    int dxy=shortest_distance(x,y);
    int dxn=shortest_distance(x,n);
    int dyn=shortest_distance(y,n);
    ans=min(d1x+dxy+dyn, d1y+dxy+dxn);
    cout<<((ans<MAX)? ans:-1);
    
    
}