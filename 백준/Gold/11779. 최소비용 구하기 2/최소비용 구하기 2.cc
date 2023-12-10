#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000

using namespace std;

typedef pair<int, int> p;
int n, m, a, b, c, x, y;
vector<p> edge[1001];
int d[1001], pi[1001];
vector<int> printer;

int dijkstra(){
    priority_queue<p, vector<p>, greater<p>> pq;

    d[x] = 0;
    pi[x] = x;
    pq.push({0, x});

    while(pq.size()){
        p u = pq.top();
        pq.pop();

        if (d[u.second] < u.first) continue;
        for (p v : edge[u.second]){
            int uv = v.first;
            if (d[v.second] > d[u.second] + uv) {
                d[v.second] = d[u.second] + uv;
                pi[v.second] = u.second;
                pq.push(v);
            }
        }
    }

    return d[y];
}

void find_path(int x, int y){
    
    if (x != y) find_path(x, pi[y]);
    printer.push_back(y);
}

void print_path(){
    cout << printer.size() << '\n';
    for (int tmp : printer){
        cout << tmp << ' ';
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        d[i] = INF;
    }
    for (int i=1; i<=m; i++){
        cin >> a >> b >> c;
        edge[a].push_back({c, b});
    }
    cin >> x >> y;

    cout << dijkstra() << '\n';
    find_path(x, y);
    print_path();
    
    return 0;
}