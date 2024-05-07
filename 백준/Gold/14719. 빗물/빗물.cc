#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int H, W;
int block[505];

void input(){
    fastio
    cin >> H >> W;
    for (int i = 1; i <= W; i ++){
        cin >> block[i];
    }
}

void solve(){
    int sum = 0;
    int i, j, k;
    for (i = 1; i <= W; i ++){
        int area = 0;
        for (j = block[i]; j >= 1; j --){
            for (k = i + 1; k < W; k ++){
                if (block[k] >= j) break;
                area ++;
            }
            if (k == W && block[k] < j) area = 0;
        }
        sum += area;
    }
    cout << sum;
}

int main(){
    input();
    solve();
    return 0;
}