#include <iostream>

using namespace std;

int n, m;
int map[51][51], visited[51][51], dp[51][51];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    string str;
    for (int i = 1; i <= n; i ++){
        cin >> str;
        for (int j = 1; j <= m; j ++){
            map[i][j] = isdigit(str[j - 1]) ? str[j - 1] - '0' : 0;
        }
    }
}

int dfs(int i, int j){
    
    if (dp[i][j]) return dp[i][j];

    int w = map[i][j];
    int cnt = 0;
    for (int d = 0; d < 4; d ++){
        int tmp;
        int ni = i + w * di[d];
        int nj = j + w * dj[d];

        if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
        if (map[ni][nj] == 0) continue;
        if (visited[ni][nj]) return -1;

        visited[ni][nj] = 1;
        if ((tmp = dfs(ni, nj)) == -1) return -1;
        else cnt = max(cnt, tmp);
        visited[ni][nj] = 0;
    }

    return dp[i][j] = cnt + 1;
}

int main(){
    input();
    cout << dfs(1, 1);
}