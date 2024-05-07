#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int cnt;
int map[10][10];
bool row[10][10], col[10][10], box[3][3][10];
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
        }
    }
}

void show(){
    for (int i = 1; i <= 9; ++ i){
        for (int j = 1; j <= 9; ++ j){
            cout << map[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

void check(int i, int j, int num, bool flag){
    cnt += (flag ? 1 : -1);
    // cout << cnt << ' ';
    map[i][j] = (flag) * num;
    row[i][num] = col[j][num] = box[(i - 1) / 3][(j - 1) / 3][num] = flag;
}

void sudoku(int r, int c){
    if (cnt == 81) {
        show();
        exit(0);
    }
    // show();
    for (int i = 1; i <= 9; ++ i){
        for (int j = 1; j <= 9; ++ j){
            if (map[i][j]) continue;
            for (int num = 1; num <= 9; ++ num){
                if (row[i][num] || col[j][num] || box[(i - 1) / 3][(j - 1) / 3][num]) continue;
                check(i, j, num, 1);
                sudoku(i, j);
                check(i, j, num, 0);
            }
            return;
        }
    }
}

void solve(){
    if (cnt == 81) {
        show();
        return;
    }
    for (int i = 1; i <= 9; ++ i){
        for (int j = 1; j <= 9; ++ j){
            if (map[i][j]) continue;
            for (int num = 1; num <= 9; ++ num){
                if (row[i][num] || col[j][num] || box[(i - 1) / 3][(j - 1) / 3][num]) continue;
                check(i, j, num, 1);
                sudoku(i, j);
                check(i, j, num, 0);
            }
            return;
        }
    }
}

int main(){
    input();
    solve();
    return 0;
}