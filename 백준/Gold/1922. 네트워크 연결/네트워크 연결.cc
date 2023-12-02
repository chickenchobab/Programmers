#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
int n, m, sum;
vector<ii> graph[1001];
priority_queue<ii, vector<ii>, greater<ii>> pq;
int visited[1001];

int main(){
    cin >> n >> m;

    int a, b, c;

    for (int i=1; i<=m; i++){
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    pq.push({0, 1});

    while(pq.size()){
        ii u = pq.top();
        pq.pop();

        if (visited[u.second]) continue;
        visited[u.second] = 1;
        sum += u.first;

        for(ii v : graph[u.second]){
            if (visited[v.second]) continue;
            pq.push(v);
        }
    }

    cout << sum;
    
}