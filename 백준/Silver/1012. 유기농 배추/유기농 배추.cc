#include <iostream>

using namespace std;

int map[50][50];
int t,n,m,k,cnt=0;

void dfs(int i, int j){
    if(i==-1 || i==n || j==-1 || j==m) return;
    if(map[i][j]!=-1) return;

    map[i][j]=1;
    dfs(i-1,j); dfs(i+1,j);
    dfs(i,j-1); dfs(i,j+1);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        cin>>m>>n>>k;
        int a,b;
        cnt=0;
        for(int i=0;i<k;i++){
            cin>>a>>b;
            map[b][a]=-1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]==-1){
                    dfs(i,j); cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
}