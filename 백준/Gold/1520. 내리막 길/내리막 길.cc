#include <iostream>
#include <algorithm>

using namespace std;

int m,n,map[501][501];
int di[]={1,-1,0,0}, dj[]={0,0,1,-1}, visited[501][501];
 
int dfs(int i, int j){
 
    if(visited[i][j]!=-1) return visited[i][j];
    if(i==1 && j==1) return visited[i][j]=1;

    visited[i][j]=0;
    for(int d=0; d<4; d++){
    int ni=i+di[d], nj=j+dj[d];

    if(ni>m || nj>n || ni<1 || nj<1) continue;
    if(map[ni][nj]<=map[i][j]) continue;
    visited[i][j]=visited[i][j]+dfs(ni,nj);    
    }
    return visited[i][j];
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            visited[i][j]=-1;
        }
    }

    dfs(m,n);
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<visited[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    
    cout<<visited[m][n];
    return 0;

}