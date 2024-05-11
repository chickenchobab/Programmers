#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
int S[21][21];
int ours, theirs, ans;
bool ispicked[21];

void input(){
    fastio
    cin >> N;
    for (int i = 1; i <= N; ++ i){
        for (int j = 1; j <= N; ++ j){
            cin >> S[i][j];
            theirs += S[i][j];
        }
    }
}

void pick(int cur, int cnt){
    if (cnt == M) {
        ans = min(ans, abs(ours - theirs));
        return;
    }
    int ours0 = ours;
    int theirs0 = theirs;
    for (int nxt = cur + 1; nxt <= N - M + cnt; ++ nxt){
        for (int con = 1; con <= N; ++ con){
            if (ispicked[con]) ours += (S[nxt][con] + S[con][nxt]);
            else theirs -= (S[nxt][con] + S[con][nxt]);
        }
        ispicked[nxt] = 1;
        pick(nxt, cnt + 1);
        ispicked[nxt] = 0;
        ours = ours0;
        theirs = theirs0;
    }
}

void solve(){
    ans = 44444;
    M = N / 2;
    // start team pick
    pick(0, 0);
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}