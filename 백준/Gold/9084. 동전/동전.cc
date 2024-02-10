#include <iostream>
#include <vector>

using namespace std;

int t, n, m;
int coin[22];

void init(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> t;
}

void input(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> coin[i];
    }
    cin >> m;
}

int solve(){
    vector<int> cnt(m + 1, 0);

    cnt[0] = 1;
    for (int i = 1; i <= n; i ++){
        for (int j = coin[i]; j <= m; j ++){
            cnt[j] += (cnt[j - coin[i]]);
        }
    }
    return cnt[m];
}

int main(){
    init();
    while(t --){
        input();
        cout << solve() << '\n';
    }
    
}