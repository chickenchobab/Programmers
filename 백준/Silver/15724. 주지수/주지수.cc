#include <iostream>

using namespace std;

int n, m, k;
int map[1025][1025], sum[1025][1025];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> map[i][j];
            sum[i][j] = map[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
        }
    }
}

int main(){
    input();

    cin >> k;
    int x1, y1, x2, y2;
    for (int i = 0; i < k; i ++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - (sum[x1 - 1][y2] + sum[x2][y1 - 1]) + sum[x1 - 1][y1 - 1] << '\n';
    }
}