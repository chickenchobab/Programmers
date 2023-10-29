#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;
int n,m,map[9][9];
int di[]={1,-1,0,0}, dj[]={0,0,1,-1}, visited[9][9];
int ans;

void bfs(){

    queue<p> q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j]==2){
                visited[i][j]=1;
                q.push({i,j});
            }
            else visited[i][j]=0;
        }
    }

    while(q.size()){
        int i,j;
        i=q.front().first, j=q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int ni=i+di[d], nj=j+dj[d];
            if(ni<1 || ni>n || nj<1 || nj>m) continue;
            if(visited[ni][nj] || map[ni][nj]) continue;
            visited[ni][nj]=1;
            q.push({ni,nj});
        }
    }
    
    int cnt=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j]==0 && visited[i][j]==0) cnt++; 
        }
    }

    ans=max(ans, cnt);
    
}

void show(){
    for(int i=1;i<=n;i++){
        for(int j=1; j<=m; j++)
            cout<<map[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}

void build(int idx){
    if(idx==3) {
        bfs(); 
        //show();
        return;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j]==0){
                map[i][j]=1;
                build(idx+1);
                map[i][j]=0;
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1; j<=m; j++){
            cin>>map[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j]==0) {
                map[i][j]=1;
                build(1);
                map[i][j]=0;
            }
        }
    }

    cout<<ans;
}