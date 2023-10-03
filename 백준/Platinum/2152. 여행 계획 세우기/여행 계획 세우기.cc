#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,s,t,a,b,idx,num;
vector<int> graph[10001];

stack<int> st;
int nid[10001],cid[10001];
int csize[10001];

queue<int> q;
int into[10001], from[10001];
vector<int> sccgraph[10001];

int dp[10001];
int turn;


int dfs(int u){
    nid[u]=++idx;
    st.push(u);

    int parent = nid[u];
    for(int v:graph[u]){
        if(!nid[v]) parent = min(parent, dfs(v));
        else if(!cid[v]) parent = min(parent, nid[v]);
    }

    if(parent == nid[u]){
        num++;
        while(1){
            int tmp=st.top();
            st.pop();
            cid[tmp]=num;
            csize[num]++;
            if(tmp==u) break;
        }
    } 
    return parent;
}

void toposort(){
    int start=0;
    from[cid[s]]=1;
    dp[cid[s]]=csize[cid[s]];
    for(int i=1;i<=num;i++){
        if(!into[i]) q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(cid[s]==u) start=1;
        for(int v:sccgraph[u]){
            if(--into[v]==0) q.push(v);
            if(from[u]) from[v]=1;
            if(start && from[v]) dp[v]=max(dp[v],dp[u]+csize[v]);
        }
    }
}

int main(){
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        if(!nid[i]) dfs(i);
    }
    
    
    for(int i=1;i<=n;i++){
        for(int tmp:graph[i]){
            if(cid[i]!=cid[tmp]){
                sccgraph[cid[i]].push_back(cid[tmp]);
                into[cid[tmp]]++;
            }
        }
    }

    toposort();
    cout<<dp[cid[t]];
    
    return 0;


}
