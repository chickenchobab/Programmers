#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m, ans;
//int map[51][51];
//int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
vector<pair<int, int>> house, store, selected_store;

void input(){
    fastio
    cin >> n >> m;
    int num;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> num;
            if (num == 1) house.push_back({i, j});
            else if (num == 2) store.push_back({i, j});
        }
    }
    ans = 50 * 50 * 13;
}

int check_distance(){
    
    int sum = 0;

    for (int h = 0; h < house.size(); h ++){
        int hi = house[h].first;
        int hj = house[h].second;
        int dist = 50 * 50 * 13;
        for (int s = 0; s < m; s ++){
            int si = selected_store[s].first;
            int sj = selected_store[s].second;
            dist = min(dist, abs(hi - si) + abs(hj - sj));
        }
        sum += dist;
    }
    
    return sum;
}

void select(int cur, int cnt){
    
    if (cnt == m) {
        ans = min(ans, check_distance());
        return;
    }

    for (int nxt = cur + 1; nxt < store.size(); nxt ++){   
        int i = store[nxt].first;
        int j = store[nxt].second;
        selected_store.push_back({i, j});
        select(nxt, cnt + 1);
        selected_store.pop_back();
    }
}

int main(){
    input();
    for (int cur = 0; cur < store.size(); cur ++){
        int i = store[cur].first;
        int j = store[cur].second;
        selected_store.push_back({i, j});
        select(cur, 1);
        selected_store.pop_back();
    }
    cout << ans;
    return 0;
}