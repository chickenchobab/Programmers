#include <iostream>
#include <algorithm>
#define MAX 10000001

using namespace std;

int n,m,a,b,c;
int graph[101][101];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            graph[i][j]=MAX;
        graph[i][i]=0;
    }
    for(int i=1; i<=m; i++){
        cin>>a>>b>>c;
        graph[a][b]=min(graph[a][b], c);
    }
    for(int sb=1; sb<=n; sb++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j) continue;
                if(i==sb || j==sb) continue;
                graph[i][j]=min(graph[i][j], graph[i][sb]+graph[sb][j]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cout<<(graph[i][j]<MAX? graph[i][j] : 0)<<' ';
        cout<<'\n';
    }
}