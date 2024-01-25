#include <iostream>

using namespace std;

int balance, pre, cur, up, down;
int bal[2], cnt[2];

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> balance;
    bal[0] = bal[1] = balance;
}

void jh(){
    if (bal[0] < cur) return;
    cnt[0] += (bal[0] / cur);
    bal[0] %= cur;
}

void sm(){
    if (up == 3 && cnt[1]){
        bal[1] += (cnt[1] * cur);
        cnt[1] = 0;
    }
    if (down == 3 && bal[1] >= cur){
        cnt[1] += (bal[1] / cur);
        bal[1] %= cur;
    }
    up = down = 0;
}

void solve(){

    cin >> pre;
    for (int i = 0; i < 13; ++ i){

        cin >> cur;
        if (cur > pre){
            up ++; down = 0;
        }
        else if (cur < pre){
            up = 0; down ++;
        }
        else {
            up = down = 0;
        }

        jh();
        sm();
        pre = cur;
    }

    int sum_jh = bal[0] + cur * cnt[0];
    int sum_sm = bal[1] + cur * cnt[1];

    if (sum_jh > sum_sm) cout << "BNP";
    else if (sum_jh < sum_sm ) cout << "TIMING";
    else cout << "SAMESAME";
}

int main(){
    init();
    solve();
}