#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int map[1001][1001];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; i ++) map[i][0] = 0;
    for (int j = 1; j <= m; j ++) map[0][j] = 0;
}

int main(){
    input();

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            int tmp = max(map[i - 1][j - 1], max(map[i - 1][j], map[i][j - 1]));
            map[i][j] = map[i][j] + tmp;
        }
    }

    cout << map[n][m];
}