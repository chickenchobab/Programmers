#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t,n,k,a,b,w;
int time[1001], ind[1001], dp[1001];
vector<int> graph[1001];
queue<int> q;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>k;
        while(!q.empty()){
            q.pop();
        }
        for(int i=1;i<=n;i++){
            ind[i]=0; dp[i]=0;
            graph[i].clear();
            cin>>time[i];
        }
        for(int i=1;i<=k;i++){
            cin>>a>>b;
            graph[a].push_back(b);
            ind[b]++;
        }
        cin>>w;

        for(int i=1;i<=n;i++){
            if(!ind[i]) {
                q.push(i);
                dp[i]=time[i];
            }
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(u==w){
                cout<<dp[w]<<'\n';
                break;
            }
            for(int v:graph[u]){
                dp[v]=max(dp[v], dp[u]+time[v]);
                if(--ind[v]==0)
                    q.push(v);
            }
        }

    }

    return 0;
}