#include <iostream>
#include <algorithm>
#include <string>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int k, l;
string ladder[1000 + 1 + 1];
string in, out;

int q;

void input(){
    fastio
    cin >> k >> l;

    in = "";
    for (int i = 0; i < k; i ++) in += 'A' + i;
    cin >> out;

    for (int i = 1; i <= l; i ++){
        cin >> ladder[i];
        if (ladder[i].front() == '?') q = i;
    }
}

int move_down(int i, int j){
    if (j > 0 && ladder[i + 1][j - 1] == '-') return j - 1;
    if (j < k && ladder[i + 1][j] == '-') return j + 1;
    return j;
}

int move_up(int i, int j){
    if (j > 0 && ladder[i - 1][j - 1] == '-') return j - 1;
    if (j < k && ladder[i - 1][j] == '-') return j + 1;
    return j;
}

void solve(){
    
    char s[k], e[k];
    int i, j, flag = 0;

    for (int idx = 0; idx < k; idx ++){
        j = idx;
        for (i = 0; i + 1 != q; i ++) {
            j = move_down(i, j);
        }
        s[j] = in[idx];
    }

    for (int idx = 0; idx < k; idx ++){
        j = idx;
        for (i = l + 1; i - 1 != q; i --) {
            j = move_up(i, j);
        }
        e[j] = out[idx];
    }

    ladder[q][0] = (s[0] == e[0])? '*' : '-';

    for (int idx = 1; idx < k - 1; idx ++){
        if (s[idx] == e[idx]) {
            if (ladder[q][idx - 1] != '*') {
                flag = 1;
                break;
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
    

    if (flag) {
        for (int i = 0; i < k - 1; i ++) cout << 'x';
    }
    else {
        cout << ladder[q];
    }
}

int main(){
    input();
    solve();
    return 0;
}