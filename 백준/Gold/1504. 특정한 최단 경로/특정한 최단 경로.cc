#include <iostream>
#include <vector>
#include <queue>
#define MAX 200000000

using namespace std;

int n,e,a,b,c,x,y,ans;
typedef pair<int,int> p;
vector<p> g[808];
int d[3][808];

void dijkstra(int num, int st){
    priority_queue<p> pq;
    for(int i=1;i<=n;i++){
        if(i==st) d[num][i]=0;
        else d[num][i]=MAX;
        pq.push({d[num][i],i});
    }
    while(pq.size()){
        p u = pq.top();
        pq.pop();
        for(p v:g[u.second]){
            int uv=v.first;
            if(d[num][v.second]>uv+d[num][u.second]) {
                d[num][v.second]=uv+d[num][u.second];
                pq.push({d[num][v.second], v.second});
            }
        }
    }
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

    dijkstra(0,1); dijkstra(1,x); dijkstra(2,y);
    ans=min(d[0][x]+d[1][y]+d[2][n], d[0][y]+d[2][x]+d[1][n]);
    cout<<((ans<MAX)? ans:-1);
    
    
}