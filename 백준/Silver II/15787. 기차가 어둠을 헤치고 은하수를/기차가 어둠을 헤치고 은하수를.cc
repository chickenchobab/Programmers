#include <iostream>
#include <set>
using namespace std;

int n, m;
int train[100001];
set<int> check;


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
        train[idx] |= (1 << (seat - 1));
    }
    else if (cmd == 2){
        cin >> seat;
        train[idx] &= (~(1 << (seat - 1)));
    }
    else if (cmd == 3) {
        train[idx] <<= 1;
        train[idx] &= ((1 << 20) - 1);
    }
    else train[idx] >>= 1; 
}

int solve(){
    int cmd, idx, cnt = 0;
    for (int i = 0; i < m; i ++){
        cin >> cmd >> idx;
        carry_out(cmd, idx);
    }
    for (int i = 1; i <= n; i ++){
        if (check.find(train[i]) == check.end()){
            cnt ++;
            check.insert(train[i]);
        }
    }
    return cnt;
}

int main(){
    init();
    cout << solve();
}