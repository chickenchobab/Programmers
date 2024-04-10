#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int n, m, wall;
int map[9][9];
bool watched[9][9];
int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};
vector<pair<int, int>> cctvs;
int direction[9];
int ans;

void input(){
    fastio
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> map[i][j];
            if (map[i][j] == 6) wall ++;
            else if (map[i][j]){
                cctvs.push_back({i, j});
            }
        }
    }
}

void watch(int i, int j, int dir){
    dir = dir % 4;
    while (1){
        watched[i][j] = 1;
        i += di[dir];
        j += dj[dir];
        if (i < 1 || i > n || j < 1 || j > m) return;
        if (map[i][j] == 6) return;
    }
}

void calculate(){

    int i, j, sum = 0;
    
    for (int c = 0; c < cctvs.size(); c ++){
        i = cctvs[c].first;
        j = cctvs[c].second;

        watch(i, j, direction[c + 1] + 1);
        if (map[i][j] == 2 || map[i][j] == 4 || map[i][j] == 5) watch(i, j, direction[c + 1] + 3);
        if (map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5) watch(i, j, direction[c + 1]);
        if (map[i][j] == 5) watch(i, j, direction[c + 1] + 2);
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if(watched[i][j] == 0) sum ++;
            watched[i][j] = 0;
        }
    }
    ans = min(ans, sum - wall);
}

// consider a step watching dir by dir

void check_the_rotation(int cur){
    int i, j;

    if (cur == cctvs.size()){
        calculate();
        // show();
        return;
    }

    for (int dir = 0; dir < 4; dir ++){
        
        direction[cur + 1] = dir;   
        check_the_rotation(cur + 1); 
    }
}

void solve(){
    ans = 100000;
    check_the_rotation(0); 
    cout << ans;
}



int main(){
    input();
    solve();
    return 0;
}