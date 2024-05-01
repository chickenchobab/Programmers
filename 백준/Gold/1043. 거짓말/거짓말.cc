#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m, k;
vector<int> knower;
vector<int> edge[101];
bool visited[101];
queue<int> q;

void input(){
    fastio
    cin >> n >> m >> k;
    int num;
    for (int i = 0; i < k; i ++){
        cin >> num;
        knower.push_back(num);
    }
}

void bfs(){
    for (int know : knower){
        q.push(know);
        visited[know] = 1;
    }

    while (q.size()){
        int cur = q.front();
        q.pop();

        for (int nxt : edge[cur]){
            if (visited[nxt]) continue;
            q.push(nxt);
            visited[nxt] = 1;
        }
    }
}

void solve(){
    int ans = 0;

    for (int i = 1; i <= m; i ++){
        cin >> k;
        int num;
        for (int j = 0; j < k; j ++){
            cin >> num;
            edge[n + i].push_back(num);
            edge[num].push_back(n + i);
        }
    }

    bfs();

    for (int i = 1; i <= m; i ++){
        if (visited[n + i] == 0) ans ++;
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}