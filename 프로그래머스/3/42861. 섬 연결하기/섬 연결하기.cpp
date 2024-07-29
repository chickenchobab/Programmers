#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int findParent(int x){
    if (parent[x] < 0) return x;
    return parent[x] = findParent(parent[x]);
}

void unite(int a, int b){
    a = findParent(a);
    b = findParent(b);
    
    if (parent[a] < parent[b])
        parent[b] = a;
    else {
        if (parent[a] == parent[b])
            parent[b]--;
        parent[a] = b;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    parent.resize(n + 1, -1);
    
    sort(costs.begin(), costs.end(), [](auto &a, auto &b){
        return a[2] < b[2];
    });
    for (auto &e : costs){
        if (findParent(e[0]) == findParent(e[1])) continue;
        answer += e[2];
        unite(e[0], e[1]);
    }
    
    return answer;
}