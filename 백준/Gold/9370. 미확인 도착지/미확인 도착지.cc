#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100000000

using namespace std;

typedef pair<int,int> p;
int test,n,m,t,s,g,h,a,b,d,dgh;
vector<p> graph[2002];
int arr[101];


void reset(){
    for(int i=1;i<=n;i++){
        graph[i].clear();
    }
}

int shortest_path(int start, int end){
    int d[2002];
    priority_queue<p, vector<p>, greater<p>> pq;
    
    for(int i=1;i<=n;i++){
        d[i]=MAX;
    }d[start]=0;

    pq.push({0,start});
    while(pq.size()){
        p u=pq.top();
        pq.pop();
        for(p v: graph[u.second]){
            int uv=v.first;
            if(d[v.second]>d[u.second]+uv){
                d[v.second]=d[u.second]+uv;
                pq.push({d[v.second], v.second});
            }
        }
    }
    return d[end];
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
            graph[a].push_back({d,b});
            graph[b].push_back({d,a});
            if(a==g && b==h) dgh=d;
            if(a==h && b==g) dgh=d;
        }
        for(int i=1;i<=t;i++){
            cin>>arr[i];
        }
        sort(arr+1, arr+t+1);
        for(int i=1;i<=t;i++){
            int d=shortest_path(s,arr[i]);
            if(d==MAX) continue;
            int dsg=shortest_path(s,g);
            int dsh=shortest_path(s,h);
            int tmp=MAX;
            tmp=min(tmp,dsg+dgh+shortest_path(h,arr[i]));
            tmp=min(tmp,dsh+dgh+shortest_path(g,arr[i]));
            if(d==tmp) cout<<arr[i]<<' ';
        }
        cout<<'\n';

    }


}