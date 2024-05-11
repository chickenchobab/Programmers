#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, L, R;
int popul[51][51];

bool visited[51][51];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
typedef pair<int, int> p;
queue<p> q;
vector<p> change;
bool found;

void input(){
    fastio
    cin >> N >> L >> R;
    for (int i = 1; i <= N; ++ i){
        for (int j = 1; j <= N; ++ j){
            cin >> popul[i][j];
        }
    }
}

bool isvalid(int i, int j, int ni, int nj){
    if (ni < 1 || ni > N || nj < 1 || nj > N) return false;
    if (visited[ni][nj]) return false;
    int gap = abs(popul[ni][nj] - popul[i][j]);
    if (gap < L || gap > R) return false;
    return true;
}

int calc_popul(int i, int j){
    int sum, cnt;
    
    sum = popul[i][j], cnt = 1;
    q.push({i, j});
    visited[i][j] = 1;

    while (q.size()){
        int i = q.front().first; 
        int j = q.front().second;
        q.pop();

        for (int d = 0; d < 4; ++ d){
            int ni = i + di[d];
            int nj = j + dj[d];
            if (isvalid(i, j, ni, nj)){
                q.push({ni, nj});
                change.push_back({ni, nj});
                visited[ni][nj] = 1;
                sum += popul[ni][nj];
                cnt ++;
            }
        }
    }

    if (cnt == 1) return -1;
    change.push_back({i, j});
    return sum / cnt;
}

void mark_popul(int p){
    for (auto area : change)
        popul[area.first][area.second] = p;
    change.clear();
}

void reset(){
    for (int i = 1; i <= N; ++ i){
        for (int j = 1; j <= N; ++ j){
            visited[i][j] = 0;
        }
    }
}

void solve(){
    int ans = 0;
    while (1){
        int p;
        found = 0;
        for (int i = 1; i <= N; ++ i){
            for (int j = 1; j <= N; ++ j){
                if (visited[i][j]) continue;
                if ((p = calc_popul(i, j)) == -1) continue;
                mark_popul(p);
                found = 1;
            }
        }
        if (found == 0) break;
        ans ++;
        reset();
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}