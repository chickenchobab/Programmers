#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
int S[21][21];
int total, sum, ans;
bool ispicked[21];

void input(){
    fastio
    cin >> N;
    for (int i = 1; i <= N; ++ i){
        for (int j = 1; j <= N; ++ j){
            cin >> S[i][j];
            total += S[i][j];
        }
    }
}

int contribute(bool picked){
    int sum = 0;
    for (int i = 1; i <= N; ++ i){
        for (int j = i + 1; j <= N; ++ j){
            if (ispicked[i] == picked && ispicked[j] == picked){
                sum += (S[i][j] + S[j][i]);
            }
        }
    }
    return sum;
}

void pick(int cur, int cnt){
    if (cnt == M) {
        ans = min(ans, abs(total - sum));
        return;
    }
    int sumcpy = sum;
    int totalcpy = total;
    for (int nxt = cur + 1; nxt <= N - M + cnt; ++ nxt){
        for (int con = 1; con <= N; ++ con){
            if (ispicked[con]) sum += (S[nxt][con] + S[con][nxt]);
            else total -= (S[nxt][con] + S[con][nxt]);
        }
        ispicked[nxt] = 1;
        pick(nxt, cnt + 1);
        ispicked[nxt] = 0;
        sum = sumcpy;
        total = totalcpy;
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