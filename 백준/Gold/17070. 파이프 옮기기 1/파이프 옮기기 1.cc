#include <iostream>

using namespace std;

int n;
int map[17][17];
int dp[17][17][3];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> map[i][j];
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 0;
        }
    }
    for (int i = 0; i <= n; i ++)
        map[i][0] = map[0][i] = 1;
}

void solve(int i, int j){

    if (map[i][j]) return;
    dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
    dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

    if (map[i - 1][j] || map[i][j - 1]) return;
    for (int k = 0; k < 3; k ++){
        dp[i][j][2] += dp[i - 1][j - 1][k];
    }
}

// void show(){
//     for (int i = 1; i <= n; i ++){
//         for (int j = 1; j <= n; j ++){
//             for (int k = 0; k < 3; k ++){
//                 cout << dp[i][j][k];
//             }
//             cout << ' ';
//         }
//         cout << '\n';
//     }
// }

int main(){

    input();

    for (int i = 2; i <= n; i ++) {
        if (map[1][i]) break;
        dp[1][i][0] = 1;
    }    

    for (int i = 2; i <= n; i ++){
        for (int j = 2; j <= n; j ++){
            solve(i, j);
        }
    }

    //show();
    
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2]; 
}