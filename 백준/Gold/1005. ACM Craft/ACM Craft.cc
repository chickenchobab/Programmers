#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t,n,k,a,b,w;
int time[1001],dp[1001];
vector<int> graph[1001];

int solve(int u){
    if(dp[u]!=-1)   return dp[u];
    int res=0;
    for(int v: graph[u]){
        res=max(res,solve(v)+time[v]);
    }
    return dp[u]=res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>k;

        for(int i=1;i<=n;i++){
            dp[i]=-1;
            graph[i].clear();
            cin>>time[i];
        }

        for(int i=1;i<=k;i++){
            cin>>a>>b;
            graph[b].push_back(a);
        }
        cin>>w;
        solve(w);
        cout<<dp[w]+time[w]<<'\n';
    }

    return 0;
}