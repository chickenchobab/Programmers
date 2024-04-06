#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int map[501][501];
int offset[13][4][2] = {
    {{0,0}, {0,1}, {0,2}, {0,3}}, {{0,0}, {1,0}, {2,0}, {3,0}},
    {{0,0}, {0,1}, {1,0}, {1,1}},
    {{0,0}, {1,0}, {2,0}, {2,1}}, {{0,0}, {0,1}, {0,2}, {-1,2}}, {{0,0}, {0,1}, {1,1}, {2,1}}, {{0,0}, {-1,0}, {-1,1}, {-1,2}},
    {{0,0}, {1,0}, {1,1}, {2,1}}, {{0,0}, {0,1}, {-1,1}, {-1,2}},
    {{0,0}, {0,1}, {1,1}, {0,2}}, {{0,0}, {1,0}, {2,0}, {1,1}}, {{0,0}, {0,1}, {-1,1}, {0,2}}, {{0,0}, {0,1}, {-1,1}, {1,1}}
};
int reflect_weight[3][2] = {
    {1,1}, {-1,1}, {1,-1}
};
int ans;

void input(){
    fastio
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> map[i][j];
        }
    }
}

void check(int i, int j){
    int sum, si, sj;
    bool err = 0;
    for (int ref = 0; ref < 3; ref ++){
        for (int shape = 0; shape < 13; shape ++){
            
            sum = 0, err = 0, si = i, sj = j;
            for (int step = 0; step < 4; step ++){
                si = i + reflect_weight[ref][0] * offset[shape][step][0];
                sj = j + reflect_weight[ref][1] * offset[shape][step][1];
                if (si < 1 || si > n || sj < 1 || sj > m) {
                    err = 1;
                    break;
                }
                sum += map[si][sj];
            }
            if (err == 0) ans = max(ans, sum);
        }
    }
    
}

void solve(){
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            check(i, j);
        }
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}