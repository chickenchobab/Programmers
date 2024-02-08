#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int parent[50];
int edge_per_node[50];

typedef pair<int, int> p;
vector<p> edges;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
}

int find_parent(int x){
    if (parent[x] < 0) return x;
    return parent[x] = find_parent(parent[x]);
}

void merge(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if (parent[a] < parent[b]){
        parent[a] += parent[b];
        parent[b] = a;
    }
    else {
        // if (parent[a] == parent[b])
        //     parent[b] --;
        parent[b] += parent[a];
        parent[a] = b;
    }
}

void init(){
    char ch;

    for (int i = 0; i < n; i ++) parent[i] = -1;
    
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cin >> ch;
            while (!isalpha(ch)) cin >> ch;

            if (i >= j || ch != 'Y') continue;
            if (find_parent(i) != find_parent(j)) {
                merge(i, j);
                edge_per_node[i] ++;
                edge_per_node[j] ++;
            }
            else edges.push_back({i, j});
        
        }
    }
    
}

bool valid(){
    if (parent[find_parent(0)] != -n) return false; 
    if (edges.size() < m - (n - 1)) return false;
    return true;
}

int main(){
    input();
    init();

    if (!valid()) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < m - (n - 1); i ++){
        int a, b;
        a = edges[i].first, b = edges[i].second;
        edge_per_node[a] ++;
        edge_per_node[b] ++;
    }
    for (int i = 0; i < n; i ++){
        cout << edge_per_node[i] << ' ';
    }

    return 0;

}