#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int arr[3][3003];

vector<int> edge[3003];
int indegree[3003];
queue<int> q;

void input(){
    fastio
    cin >> n;
    int t;
    
    for (int i = 0; i < 3; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> t;
            arr[i][j] = t;
        }
    }
}

void make_graph(){

    int cnt[n + 1] = {0,};

    for (int j = 1; j <= n; j ++){
        vector<pair<int ,int>> num;
        for (int i = 0; i < 3; i ++){
            cnt[arr[i][j]] ++;
            num.push_back({i, j});
        }
        
        for (int i = 0; i < 3; i ++){
            int a, b;
            a = num[i].first, b = num[i].second;
            if (cnt[arr[a][b]] == 1) arr[a][b] = 0;
        }
    }

    // for (int i = 0; i < 3; i ++){
    //     for (int j = 1; j <= n; j ++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < 3; i ++){
        int a, b;
        a = arr[i][0];
        for (int j = 1; j <= n; j ++){
            b = arr[i][j];
            if (a && b) {
                edge[a].push_back(b);
                indegree[b] ++;
            }
            if (b) a = b;
        }
    }
}

void topo_sort(){
    for (int i = 1; i <= n; i ++){
        if (indegree[i] == 0) q.push(i);
    }

    while (q.size()){
        int u = q.front();
        q.pop();
        cout << u << ' ';
        for (int v : edge[u]){
            if (--indegree[v] == 0){
                q.push(v);
            }
        }
    }
}

int main(){
    input();
    make_graph();
    topo_sort();
    return 0;
}