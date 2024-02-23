#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#define MAX 100000000
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, k;

typedef pair<int, int> p;
long long ans;
queue<p> q;
set<int> visited;
int dx[] = {1, -1};

void input(){
    fastio
    cin >> n >> k;
    int well;
    for (int i = 0; i < n; i ++){
        cin >> well;
        q.push({well, well});
        visited.insert(well);
    }
}

void bfs(){

    while (q.size()){
        int cur = q.front().first;
        int well = q.front().second;
        q.pop();
        for (int i = 0; i < 2; i ++){
            int nxt = cur + dx[i];
            if (visited.find(nxt) != visited.end()) continue;
            visited.insert(nxt);
            q.push({nxt, well});
            ans += abs(nxt - well);
            if (-- k == 0) return;
        }
    }
}

int main(){
    input();
    bfs();
    cout << ans;
    return 0;
}