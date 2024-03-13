#include <iostream>
#include <algorithm>
#define MAX (64 * 64)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
bool map[64][64];

void input(){
    fastio
    cin >> n;
    string str;
    for (int i = 0; i < n; i ++){
        cin >> str;
        for (int j = 0; j < n; j ++){
            map[i][j] = str[j] - '0';
        }
    }
}

string solve(int i, int j, int sz){

    if (sz == 1) {
        if (map[i][j]) return "1";
        return "0";
    }

    string sum = "";
    sum += solve(i, j, sz / 2);
    sum += solve(i, j + sz / 2, sz / 2);
    sum += solve(i + sz / 2, j, sz / 2);
    sum += solve(i + sz / 2, j + sz / 2, sz / 2);

    if (sum == "0000") return "0";
    else if (sum == "1111") return "1";
    else return ("(" + sum + ")");
}

int main(){
    input();
    cout << solve(0, 0, n);
    return 0;
}