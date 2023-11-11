#include <iostream>
#include <algorithm>
#define MAX 4444444

using namespace std;

int n, e, a, b, c, ans;
int graph[401][401];

int main(){
    cin>>n>>e;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            graph[i][j]=MAX;
        }
    }

    for(int i=1; i<=e; i++){
        cin>>a>>b>>c;
        graph[a][b]=c;
    }

    for(int sb=1; sb<=n; sb++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                graph[i][j]=min(graph[i][j], graph[i][sb]+graph[sb][j]);
            }
        }
    }

    ans=MAX;
    for(int i=1; i<=n; i++){
        ans=min(ans, graph[i][i]);
    }
    cout<<(ans==MAX? -1: ans);
}