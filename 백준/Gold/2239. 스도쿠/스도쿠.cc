#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int map[10][10];
bool row[10][10], col[10][10], box[3][3][10];
vector<pair<int, int>> blank;
void check(int i, int j, int num, bool flag);

void input(){
    fastio
    int num;
    string str;
    for (int i = 1; i <= 9; ++ i){
        cin >> str;
        for (int j = 1; j <= 9; ++ j){
            num = str[j - 1] - '0';
            if (num) check(i, j, num, 1);
            else blank.push_back({i, j});
        }
    }
}

void show(){
    for (int i = 1; i <= 9; ++ i){
        for (int j = 1; j <= 9; ++ j)
            cout << map[i][j];
        cout << '\n';
    }
}

void check(int i, int j, int num, bool flag){
    map[i][j] = (flag) * num;
    row[i][num] = col[j][num] = box[(i - 1) / 3][(j - 1) / 3][num] = flag;
}

void sudoku(int idx){
    if (idx == blank.size()) {
        show();
        exit(0);
    }

    int i, j;
    pair<int, int> p = blank[idx];
    i = p.first, j = p.second;
    for (int num = 1; num <= 9; ++ num){
        if (row[i][num] || col[j][num] || box[(i - 1) / 3][(j - 1) / 3][num]) continue;
        check(i, j, num, 1);
        sudoku(idx + 1);
        check(i, j, num, 0);
    }
}

void solve(){
    sudoku(0);
}

int main(){
    input();
    solve();
    return 0;
}