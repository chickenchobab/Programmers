#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;
int n,m,map[9][9];
int di[]={1,-1,0,0}, dj[]={0,0,1,-1}, visited[9][9];
int ans;

void show(){
    cout<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<visited[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<"\n\n";
}

void dfs(int i, int j){

    visited[i][j]=1;
    for(int d=0;d<4;d++){
        int ni=i+di[d], nj=j+dj[d];
        if(ni<1 || ni>n || nj<1 || nj>m) continue;
        if(visited[ni][nj] || map[ni][nj]) continue;
        dfs(ni,nj);
    }
    
}

void build(int idx){
    if(idx==3) {
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                visited[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(map[i][j]==2) dfs(i,j);
            }
        }
        int cnt=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(map[i][j]==0 && visited[i][j]==0)
                cnt++;
            }     
        }
        ans=max(ans,cnt);
        return;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j]!=0) continue;
            map[i][j]=1;
            build(idx+1);
            map[i][j]=0;
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

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j]!=0) continue;
            map[i][j]=1;
            build(1);
            map[i][j]=0;
        }     
    }

    cout<<ans;
}