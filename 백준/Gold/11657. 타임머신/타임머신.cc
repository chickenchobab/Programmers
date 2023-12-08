#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define INF 111111111

using namespace std;

typedef tuple<int, int, int> iii;
int n, m, a, b, c;
long long d[555];
vector<iii> edge;

void bellman_ford(){

    for(int i=1; i<=n; i++){
        for(iii j : edge){
            int a = get<0>(j);
            int b = get<1>(j);
            int ab = get<2>(j);

            if(d[a] == INF) continue;
            if(d[b] > d[a] + ab) {
                if(i == n){
                    cout<<-1;
                    return;
                }
                d[b] = d[a] + ab;
            }
        }
    }
    
    for(int i=2; i<=n; i++){
        if(d[i] == INF) cout<<-1<<'\n';
        else cout<<d[i]<<'\n';
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;

    for(int i=1; i<=n; i++) 
        d[i]=INF;
    d[1]=0;

    for(int i=1; i<=m; i++){
        cin>>a>>b>>c;
        edge.push_back({a,b,c});
    }
    
    bellman_ford();
    
    return 0;
}