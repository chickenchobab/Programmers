#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int map[101][101];
int rotate_matrix[4][2][2] = {{{1, 0}, {0, 1}}, {{0, -1}, {1, 0}}, {{-1, 0}, {0, -1}}, {{0, 1}, {-1, 0}}};
int offset[5][3][2] = 
{{{0, 1}, {0, 2}, {0, 3}}, 
{{0, 1}, {1, 1}, {1, 2}}, 
{{0, 1}, {0, 2}, {1, 2}}, 
{{0, 1}, {0, 2}, {1, 1}}, 
{{0, 1}, {1, 0}, {1, 1}}};
int ans;


bool input(){
    cin >> n;
    if (n == 0) return false;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> map[i][j];
        }
    }
    return true;
}

int dot(int u[2], int v[2]){
    return u[0] * v[0] + u[1] * v[1];
}

void check(int i, int j, int type, int dir){
    int sum = map[i][j];

    for (int step = 0; step < 3; step ++){
        int ni = i + dot(rotate_matrix[dir][0], offset[type][step]);
        int nj = j + dot(rotate_matrix[dir][1], offset[type][step]);
        
        if (ni < 1 || ni > n || nj < 1 || nj > n) return;
        sum += map[ni][nj];
    }
    
    ans = max(ans, sum);
}

void solve(int turn){
    for (int i = 1; i <= n; i ++ ){
        for (int j = 1; j <= n; j ++){
            for (int type = 0; type < 5; type ++) {
                for (int dir = 0; dir < 4; dir ++){
                    check(i, j, type, dir);
                }
            }
        }
    }
    cout << turn << ". " << ans << '\n';
}

int main(){
    fastio
    int turn = 0;
    while (1){
        if (input() == false) return 0;
        ans = -4444444;
        solve(++turn);
    }
    return 0;
}