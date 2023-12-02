#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define INF 100000000

using namespace std;

typedef tuple<int, int, int> iii;
int n, m, w, s, e, t;
int d[555];
int TC;
vector<iii> edge;

bool bellman_ford(){

    d[1] = 0;

    for (int i=1; i<=n-1; i++){
        for(iii j : edge){
            int a, b, ab;
            tie(a, b, ab) = {get<0>(j), get<1>(j), get<2>(j)};
            //if(d[a] == INF) continue;
            if(d[b] > d[a] + ab) d[b] = d[a] + ab;
        }
    }
    for (iii j : edge){
        int a, b, ab;
        tie(a, b, ab) = {get<0>(j), get<1>(j), get<2>(j)};
        if(d[b] > d[a] + ab) return false;
    }
    return true;
}

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> TC;
    while (TC--){

        cin >> n >> m >> w;

        for (int i=1; i<=n; i++){
            d[i] = INF;
        }
        edge.clear();

        for (int i=1; i<=m; i++){
            cin >> s >> e >> t;
            edge.push_back({s, e, t});
            edge.push_back({e, s, t});
        }
        for (int i=1; i<=w; i++){
            cin >> s >> e >> t;
            edge.push_back({s, e, -t});
        }

        !bellman_ford() ? cout << "YES\n" : cout << "NO\n";
        


    }
    

}