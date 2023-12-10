#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

typedef pair<int, int> p;
int n, m, a, b, c, sum, cnt, max_cost;
vector<p> edge[100001];
priority_queue<p, vector<p>, greater<p>> pq;
int visited[100001];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i=1; i<=m; i++){
        cin >> a >> b >> c;
        edge[a].push_back({c, b});
        edge[b].push_back({c, a});
    }

    pq.push({0, 1});

    while(pq.size()){

        p u = pq.top();
        pq.pop();
        
        if (visited[u.second]) continue;

        max_cost = max(max_cost, u.first);
        visited[u.second] = 1;
        sum += u.first;
        cnt ++;

        for (p v : edge[u.second]){
            pq.push({v.first, v.second});
        }
    }

    cout << sum - max_cost;
}