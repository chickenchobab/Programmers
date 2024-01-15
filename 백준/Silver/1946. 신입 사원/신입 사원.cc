#include <iostream>
#include <algorithm>

using namespace std;

int t;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
}

int solve(){
    int n, a, b, tmp, cnt;
    int rank[100001];

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a >> b;
        rank[a] = b;
    }

    tmp = rank[1];
    cnt = 1;
    for (int i = 2; i <= n; i ++){
        if (rank[i] > tmp) continue;
        tmp = rank[i];
        cnt ++;
    }
    return cnt;
}

int main(){
    input();
    while (t --){
        cout << solve() << '\n';
    }
}