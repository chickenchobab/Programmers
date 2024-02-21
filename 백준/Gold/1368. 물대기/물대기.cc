#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
typedef tuple<int, int, int> edge;
vector<edge> edges;

int parent[301];

void input(){
    fastio
    cin >> n;

    int cost;
    for (int i = 1; i <= n; i ++) {
        cin >> cost;
        edges.push_back({cost, 0, i});
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> cost;
            if (i < j) edges.push_back({cost, i, j}); 
        }
    }
}

void init(){
    for (int i = 0; i <= n; i ++) parent[i] = -1;
}

int find(int x){
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a), b = find(b);
    if (parent[a] < parent[b])
        parent[b] = a;
    else {
        if (parent[a] == parent[b])
            parent[b] --;
        parent[a] = b;
    }
}

int mst(){
    int sum = 0;
    sort(edges.begin(), edges.end());

    int a, b, dist;
    for (edge e : edges){
        dist = get<0>(e);
        a = get<1>(e);
        b = get<2>(e);

        if (find(a) == find(b)) continue;
        //cout << dist << ' ' << a << ' ' << b << '\n';
        merge(a, b);
        sum += dist;
    }

    return sum;
}


int main(){
    input();
    init();
    cout << mst();
    return 0;
}