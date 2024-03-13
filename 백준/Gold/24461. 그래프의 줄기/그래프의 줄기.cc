#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
vector<int> edges[100000];

// 시간초과 나는 코드 보기
int connected[100000], turn_idx[100000], turn_cnt[100000];
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
    sort(ans.begin(), ans.end());
    for (int tmp : ans) cout << tmp << ' ';
}

void toposort(){

    for (int i = 0; i < n; i ++) {
        if (connected[i] == 1) {
            q.push_back(i);
            turn_idx[i] = 0;
            turn_cnt[0] ++;
        }
    }

    while (q.size()){
        int u = q.front();
        q.pop_front();
        connected[u] --;

        if (turn_cnt[turn_idx[u]] <= 2) {
            ans.push_back(u);
        }

        for (int v : edges[u]){
            if (-- connected[v] == 1){
                q.push_back(v);
                turn_idx[v] = turn_idx[u] + 1;
                turn_cnt[turn_idx[v]] ++;
            } 
        }
    }

}

int main(){
    input();
    toposort();
    print();
    return 0;
}