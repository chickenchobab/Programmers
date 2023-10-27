#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstdio>

using namespace std;

typedef pair<int,int> p;
int n,m,k,map[1001][1001];
int visited[1001][1001], di[]={1,-1,0,0}, dj[]={0,0,1,-1};
queue<pair<p,int>> q;
int step;

int bfs(){
    q.push({{1,1},k});
    visited[1][1]=k;

    while(!q.empty()){
        step++;
        int stepcnt = q.size();
        while(stepcnt--){
            pair<p,int> tmp=q.front();
            q.pop();

            int i=tmp.first.first;
            int j=tmp.first.second;
            int chance = tmp.second;

            if(i==n && j==m) return step;
            for(int d=0;d<4;d++){
                int ni=i+di[d], nj=j+dj[d];
                if(ni>n || ni<1 || nj>m || nj<1) continue;
                if(map[ni][nj]){
                    if(chance==0) continue;
                    if(visited[ni][nj]>=chance-1) continue;
                    visited[ni][nj]=chance-1;
                    q.push({{ni,nj},chance-1});
                }
                else {
                    if(visited[ni][nj]>=chance) continue;
                    visited[ni][nj]=chance;
                    q.push({{ni,nj},chance});
                }
            }
        }
        
    }
    return -1;
    
}

int main(){
    ios::sync_with_stdio(false);

    cin>>n>>m>>k; 

    for(int i=1;i<=n;i++){
        string str;
        cin>>str;

        for(int j=1;j<=m;j++){
            map[i][j]=str[j-1]-'0';
            visited[i][j]=-1;
        }
    }

    cout<<bfs();

    return 0;
}