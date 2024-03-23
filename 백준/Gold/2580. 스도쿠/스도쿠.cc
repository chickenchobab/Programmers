#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int map[9][9];

int n;
vector<pair<int, int>> blank;

void input(){
    fastio
    int num;
    for (int i = 0; i < 9; i ++){
        for (int j = 0; j < 9; j ++){
            cin >> num;
            map[i][j] = num;
            if (num == 0) blank.push_back({i, j});
        }
    }
    n = blank.size();
}

bool check_entry(int i, int j, int num){
    int x, y, dx, dy;
    for (x = 0; x < 9; x ++){
        if (map[i][x] == num) return false;
    }
    for (y = 0; y < 9; y ++){
        if (map[y][j] == num) return false;
    }

    x = (i / 3) * 3, y = (j / 3) * 3;

    for (int a = 0; a < 3; a ++){
        for (int b = 0; b < 3; b ++){
            if (map[x + a][y + b] == num) return false;
        }
    }
    return true;
}

void show_map(){
    for (int i = 0; i < 9; i ++){
        for (int j = 0; j < 9; j ++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

void dfs(int cnt){
    int i, j;

    if (cnt == n) {
        show_map();
        exit(0);
    }
    
    i = blank[cnt].first, j = blank[cnt].second;
    for (int num = 1; num <= 9; num ++){
        if (check_entry(i, j, num)) {
            map[i][j] = num;
            dfs(cnt + 1);
            map[i][j] = 0;
        }
    }
}


int main(){
    input();

    if (n) dfs(0);
    else show_map();

    return 0;
}