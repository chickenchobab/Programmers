#include <iostream>

using namespace std;

int n, m;
int train[100001];

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
}

// void show_binary_number(int num){
//     for (int i = 20; i >= 0; --i) {
//         int result = num >> i & 1;
//         cout << result;
//     }
//     cout << '\n';
// }

void carry_out(int cmd, int idx){
    int seat;
    if (cmd == 1){
        cin >> seat;
        train[idx] = train[idx] | (1 << (seat - 1)) & ((1 << 20) - 1);
    }
    else if (cmd == 2){
        cin >> seat;
        train[idx] = train[idx] & ~(1 << (seat - 1)) & ((1 << 20) - 1);
    }
    else if (cmd == 3) train[idx] = train[idx] << 1 & ((1 << 20) - 1); 
    else train[idx] = train[idx] >> 1 & ((1 << 20) - 1); 
}

int solve(){
    int cmd, idx, cnt = 0;
    for (int i = 0; i < m; i ++){
        cin >> cmd >> idx;
        carry_out(cmd, idx);
    }
    for (int i = 1; i <= n; i ++){
        int flag = 1;
        for (int j = 1; j <= i - 1; j ++){
            if (train[j] == train[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) cnt ++;
    }

    return cnt;
}

int main(){
    init();
    cout << solve();
}