#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100000000

using namespace std;

typedef pair<int,int> p;
int test,n,m,t,s,g,h,a,b,d,dgh;
vector<p> graph[2002];
int arr[101], dist[2002];

void reset(){
    for(int i=1;i<=n;i++){
        graph[i].clear();
    }
}

void dijkstra(){
    
    priority_queue<p, vector<p>, greater<p>> pq;
    
    for(int i=1;i<=n;i++){
        dist[i]=MAX;
    }dist[s]=0;

    pq.push({0,s});
    while(pq.size()){
        p u=pq.top();
        pq.pop();
        for(p v: graph[u.second]){
            int uv=v.first;
            if(dist[v.second]>dist[u.second]+uv){
                dist[v.second]=dist[u.second]+uv;
                pq.push({dist[v.second], v.second});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    while(test--){
        cin>>n>>m>>t>>s>>g>>h;
        reset();
        for(int i=1;i<=m;i++){
            cin>>a>>b>>d;
            d*=2;
            if(a==g && b==h) d--;
            if(a==h && b==g) d--;
            graph[a].push_back({d,b});
            graph[b].push_back({d,a});
        }
        for(int i=1;i<=t;i++){
            cin>>arr[i];
        }
        sort(arr+1, arr+t+1);
        dijkstra();
        for(int i=1;i<=t;i++){
            if(dist[arr[i]]%2==1) cout<<arr[i]<<' ';
        }
        cout<<'\n';

    }
    return 0;

}