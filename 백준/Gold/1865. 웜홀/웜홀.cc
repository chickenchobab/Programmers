#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define INF 100000000

using namespace std;

typedef tuple<int, int, int> iii;
int n, m, w, s, e, t;
int d[555];
int TC, flag;
vector<iii> edge;
vector<int> wsp;

bool bellman_ford(){
    for (int i=1; i<=n-1; i++){
        for(iii j : edge){
            int a, b, ab;
            tie(a, b, ab) = {get<0>(j), get<1>(j), get<2>(j)};
            if(d[a] == INF) continue;
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
    cin >> TC;
    while (TC--){

        cin >> n >> m >> w;
        edge.clear();
        wsp.clear();
        flag = 0;

        for (int i=1; i<=m; i++){
            cin >> s >> e >> t;
            edge.push_back({s, e, t});
            edge.push_back({e, s, t});
        }
        for (int i=1; i<=w; i++){
            cin >> s >> e >> t;
            edge.push_back({s, e, -t});
            wsp.push_back(s);
        }
        
        for (int st : wsp){
            for (int i=1; i<=n; i++) d[i] = INF;
            d[st] = 0;
            if (!bellman_ford()) {
                cout << "YES\n";
                flag = 1;
                break;
            }
        }

        if (flag == 0) cout << "NO\n";

    }
    

}