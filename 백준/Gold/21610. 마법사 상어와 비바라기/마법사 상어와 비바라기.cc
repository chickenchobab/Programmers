#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
int water[50][50];
bool check[50][50];
int di[] = {0, -1, -1, -1, 0, 1, 1, 1}, dj[] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<pair<int, int>> clouds;

void input(){
    fastio
    cin >> N >> M;
    for (int i = 0; i < N; ++ i){
        for (int j = 0; j < N; ++ j){
            cin >> water[i][j];
        }
    }
}

void move_and_rain(int d, int s){
    int cnt = clouds.size();
    for (int c = 0; c < cnt; ++ c){
        int spd = s;
        while (spd --){
            clouds[c].first = (clouds[c].first + di[d] + N) % N;
            clouds[c].second = (clouds[c].second + dj[d] + N) % N;
        }
        int i = clouds[c].first;
        int j = clouds[c].second;
        water[i][j] ++;
        check[i][j] = 1;   
    }
    // show();
    clouds.clear();
}

void irrigate(){
    for (int i = 0; i < N; ++ i){
        for (int j = 0; j < N; ++ j){
            if (check[i][j] == 0) continue;
            int cnt = 0;
            for (int d = 1; d <= 7; d += 2){
                int ni = i + di[d];
                int nj = j + dj[d];
                if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
                if (water[ni][nj] == 0) continue;
                cnt ++;
            }
            water[i][j] += cnt;
        }
    }
}

void evaporate(){
    for (int i = 0; i < N; ++ i){
        for (int j = 0; j < N; ++ j){
            if (check[i][j] == 0 && water[i][j] >= 2){
                clouds.push_back({i, j});
                water[i][j] -= 2;
            }
            check[i][j] = 0;
        }
    }
}

void solve(){
    int ans = 0, d, s;
    clouds.push_back({N - 1, 0});
    clouds.push_back({N - 1, 1});
    clouds.push_back({N - 2, 0});
    clouds.push_back({N - 2, 1});
    while (M --){
        cin >> d >> s;
        d --;
        move_and_rain(d, s);
        irrigate();
        evaporate();
    }
    for (int i = 0; i < N; ++ i){
        for (int j = 0; j < N; ++ j){
            ans += water[i][j];
        }
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}