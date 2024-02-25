#include <iostream>
#include <algorithm>
#include <string>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int m, n;
string ladder[1001];
char in[27], out[27];

int q;

void input(){
    fastio
    string str;
    cin >> m >> n >> str;

    for (int i = 0; i < m; i ++) {
        in[i] = 'A' + i;
        out[i] = str[i];
    }

    for (int i = 0; i < n; i ++){
        cin >> ladder[i];
        if (ladder[i].front() == '?') q = i;
    }
}

void input_down(){
    for (int i = 0; i < q; i ++){
        for (int j = 0; j < m - 1; j ++){
            if (ladder[i][j] == '-')
                swap(in[j], in[j + 1]);
        }
    }
}

void output_up(){
    for (int i = n - 1; i > q; i --){
        for (int j = 0; j < m - 1; j ++){
            if (ladder[i][j] == '-')
                swap(out[j], out[j + 1]);
        }
    }
}

bool compare_up_down(){

    ladder[q][0] = (in[0] == out[0])? '*' : '-';

    for (int idx = 1; idx < m - 1; idx ++){
        if (in[idx] == out[idx]) {
            if (ladder[q][idx - 1] != '*') {
                return false;
            }
            ladder[q][idx] = '*';
        }
        else {
            if (ladder[q][idx - 1] != '-'){
                ladder[q][idx] = '-';
            }
            else if (ladder[q][idx - 1] == '-'){
                ladder[q][idx] = '*';
            }
        }
    }
    
    return true;
}


void solve(){

    input_down();
    output_up();

    if (compare_up_down()) cout << ladder[q];
    else {
        for (int i = 0; i < m - 1; i ++) cout << 'x';
    }
}

int main(){
    input();
    solve();
    return 0;
}