#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
vector<int> edges[100000];

int connected[100000];
bool pruned[100000];
deque<int> q;
vector<int> ans;

void input(){
    fastio
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i ++){
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        connected[a] ++;
        connected[b] ++;
    }
}

void print(){
    for (int i = 0; i < n; i ++){
        if (pruned[i] == 0) cout << i << ' ';
    }
}

void prune(){
    for (int i = 0; i < n; i ++){
        if (connected[i] == 1) pruned[i] = 1;
    }
}

void toposort(){

    int cnt = 0;
    
    for (int i = 0; i < n; i ++) {
        if (connected[i] == 1) {
            q.push_back(i);
            cnt ++;
        }
    }

    if (cnt <= 2) return;
    prune();
    
    while (q.size() > 2){
        int loop = q.size();
        vector<int> nxt;
        while (loop --){
            int u = q.front();
            q.pop_front();
            connected[u] --;
            for (int v : edges[u]){
                if(-- connected[v] == 1 && pruned[v] == 0) {
                    q.push_back(v);
                    nxt.push_back(v);
                }
            }
        }
        if (nxt.size() <= 2) return;
        for (int tmp : nxt) pruned[tmp] = 1;
    }
}

int main(){
    input();
    toposort();
    print();
    return 0;
}