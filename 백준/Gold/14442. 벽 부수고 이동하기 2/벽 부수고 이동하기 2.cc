#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstdio>

using namespace std;

typedef pair<int,int> p;
int n,m,k,map[1001][1001];
int visited[1001][1001][11], di[]={1,-1,0,0}, dj[]={0,0,1,-1};
queue<pair<p,int>> q;

int bfs(){
    q.push({{1,1},0});
    visited[1][1][0]=1; 

    while(!q.empty()){

        pair<p,int> tmp=q.front();
        q.pop();
        int i=tmp.first.first;
        int j=tmp.first.second;
        int cnt=tmp.second;
        if(i==n && j==m) return visited[i][j][cnt];
        
        for(int d=0;d<4;d++){
            int ni=i+di[d], nj=j+dj[d];
            if(ni>n || ni<1 || nj>m || nj<1) continue;
            if(map[ni][nj]){
                if(cnt==k) continue;
                if(visited[ni][nj][cnt+1]) continue;
                visited[ni][nj][cnt+1]=visited[i][j][cnt]+1;
                q.push({{ni,nj},cnt+1});
            }
            else if(visited[ni][nj][cnt]==0){
                visited[ni][nj][cnt]=visited[i][j][cnt]+1;
                q.push({{ni,nj},cnt});
            }
        }
    }
    return -1;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>k; 
    cin.ignore();

    for(int i=1;i<=n;i++){
        string str;
        getline(cin,str);

        for(int j=1;j<=m;j++){
            map[i][j]=str[j-1]-'0';
            for(int l=0; l<=k; l++){
                visited[i][j][l]=0;
            }
        }
    }

    cout<<bfs();

    return 0;
}