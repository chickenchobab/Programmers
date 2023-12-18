#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 100000001

using namespace std;

typedef pair<long long, int> p;
int n;
vector<p> edge[1001];
priority_queue<p, vector<p>, greater<p>> pq;
int visited[1001];
long long d[1001];

long long prim(){

    long long ans = 0;

    for (int i=1; i<=n; i++) d[i] = INF;

    pq.push({0, 1});
    d[1] = 0;

    while(pq.size()){
        p u = pq.top();
        pq.pop();

        if (visited[u.second]) continue;
        ans += u.first;
        visited[u.second] = 1;
        // cout << ans <<' ';

        for (p v : edge[u.second]){
            int uv = v.first; 
            if (d[v.second] <= uv) continue;
            d[v.second] = uv;
            pq.push({v.first, v.second}); 
        }
    }

    return ans;
}

int main(){
    cin >> n;

    int cost;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> cost;
            if (i == j) continue;
            edge[i].push_back({cost, j});
        }
    }

    cout << prim();

}