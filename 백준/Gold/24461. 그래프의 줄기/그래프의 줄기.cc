#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,a,b;
vector<int> graph[100000];

int flag;
int edge[100000], turn[100000], cnt[100000], line[100000];
vector<int> ans;

int main(){
    
    cin>>n;

    for(int i=1;i<=n-1;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edge[a]++; edge[b]++;
    }

    queue<int> q;

    for(int i=0;i<n;i++){
        if(edge[i]==1){
            q.push(i);
            turn[i]=1;
            cnt[turn[i]]++;
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        edge[u]--;

        if(cnt[turn[u]]<=2) {
            flag=1;
            line[u]=1;
        }

        for(int v: graph[u]){

            if(--edge[v]==1){
                q.push(v);
                turn[v]=turn[u]+1;
                cnt[turn[v]]++;
                
                if(flag) line[v]=1;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(line[i]) ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    for(int i:ans) cout<<i<<' ';


    

    






}