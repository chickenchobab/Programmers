#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstdio>

using namespace std;

typedef pair<int,int> p;
int n,m,map[1001][1001];
int visited[1001][1001][2], di[]={1,-1,0,0}, dj[]={0,0,1,-1};
queue<pair<p,int>> q;

int bfs(){
    q.push({{1,1},0});
    visited[1][1][0]=0;  
    while(!q.empty()){
        pair<p,int> tmp=q.front();
        q.pop();
        int i=tmp.first.first;
        int j=tmp.first.second;
        int block=tmp.second;
        for(int d=0;d<4;d++){
            int ni=i+di[d], nj=j+dj[d];
            if(ni>n || ni<1 || nj>m || nj<1) continue;
            if(map[ni][nj]){
                if(block) continue;
                visited[ni][nj][1]=visited[i][j][block]+1;
                q.push({{ni,nj},1});
            }
            else if(visited[ni][nj][block]==-1){
                visited[ni][nj][block]=visited[i][j][block]+1;
                q.push({{ni,nj},block});
            }
        }
    }
    int a=visited[n][m][0], b=visited[n][m][1];
    if(a==-1 && b==-1) return -1;
    else if(a==-1 || b==-1) return max(a,b)+1;
    else return min(a,b)+1;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m; 
    cin.ignore();

    for(int i=1;i<=n;i++){
        string str;
        getline(cin,str);

        for(int j=1;j<=m;j++){
            int tmp=str[j-1]-'0';
            map[i][j]=tmp;
            visited[i][j][0]=visited[i][j][1]=-1;
        }
    }

    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%8d",visited[i][j][0]);
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%8d",visited[i][j][1]);
    //     }
    //     cout<<endl;
    // }

    cout<<bfs();

    return 0;
}