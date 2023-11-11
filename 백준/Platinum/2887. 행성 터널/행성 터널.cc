#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 2000000000

using namespace std;

typedef tuple<int, int, int> tpl;
typedef pair<int, int> p;
int n, x, y, z, ans, cnt;

priority_queue<tpl, vector<tpl>, greater<tpl>> pq;
vector<p> edge[3];
int parent[100001];

void init(){
    for(int i=1; i<=n; i++)
        parent[i]=-1;
}

int find(int x){
    if(parent[x]<0) return x;
    return parent[x]=find(parent[x]);
}

void merge(int a, int b){
    a=find(a);
    b=find(b);
    if(parent[a]<parent[b])
        parent[b]=a;
    else{
        if(parent[a]==parent[b])
            parent[b]--;
        parent[a]=b;
    }
}

int main(){
    cin>>n;

    init();

    for(int i=1;i<=n;i++){
        cin>>x>>y>>z;
        edge[0].push_back({x,i});
        edge[1].push_back({y,i});
        edge[2].push_back({z,i});
    }
    
    for(int i=0;i<3;i++){
        sort(edge[i].begin(), edge[i].end());
        for (int pos = 1; pos < edge[i].size(); pos++){
            int d = abs(edge[i][pos].first - edge[i][pos-1].first);
            int s = edge[i][pos-1].second;
            int e = edge[i][pos].second;

            pq.push({d,s,e});
        }
    }

    while(pq.size()){
            tpl tmp = pq.top();
            pq.pop();
            int a=get<1>(tmp);
            int b=get<2>(tmp);
            int d=get<0>(tmp);
            if(find(a)==find(b)) continue;
            //cout<<d<<' '<<a<<' '<<b<<'\n';
            merge(a,b);
            ans+=d;
    }

    cout<<ans;

}