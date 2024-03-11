#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, l;
int height[101][101];

int ans;
int di[] = {1, 0}, dj[] = {0, 1};

void input(){
    fastio
    cin >> n >> l;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> height[i][j];
        }
    }
} 

void move(int i, int j, int dir, int flat_cnt, int slope_cnt){
    if ((dir == 0 && i == n) || (dir == 1 && j == n)) {
        if (slope_cnt > 0 && slope_cnt < l) return;
        ans ++;
        // dir ? cout << i << " east done\n" : cout << j << " south done\n";
        return;
    }

    int ni = i + di[dir], nj = j + dj[dir];
    if (height[i][j] == height[ni][nj]) {
        if (slope_cnt > 0 && slope_cnt < l) move(ni, nj, dir, flat_cnt + 1, slope_cnt + 1);
        else if (slope_cnt == l) move(ni, nj, dir, 1, 0);
        else move(ni, nj, dir, flat_cnt + 1, 0);
    }
    else if (height[i][j] - height[ni][nj] == 1 && ((slope_cnt == l) || (slope_cnt == 0))) move(ni, nj, dir, 1, 1);
    else if (height[ni][nj] - height[i][j] == 1 && flat_cnt >= l && slope_cnt == 0) move(ni, nj, dir, 1, 0);
}



int main(){
    input();

    for (int i = 1; i <= n; i ++){
        move(1, i, 0, 1, 0);
        move(i, 1, 1, 1, 0);
    }
    
    cout << ans;

    return 0;
}