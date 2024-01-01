#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
typedef pair<int, int> ii;
ii box[101];
int dp[100001];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int w, v;
    for (int i = 1; i <= n; i ++){
        cin >> w >> v;
        box[i] = {w, v};
    }
    box[0] = {0, 0};
}

int main(){

    input();

    // sort(box + 1, box + n + 1);

    int ans = 0;

    for (int i = 1; i <= n ; i ++){
        for (int j = k; j >= box[i].first; j --){
            dp[j] = max(dp[j], dp[j - box[i].first] + box[i].second);
        }
    }

    cout << dp[k];
}