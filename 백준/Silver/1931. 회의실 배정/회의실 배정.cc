#include <iostream>
#include <algorithm>

using namespace std;

int n;
typedef long long ll;
typedef pair<int, int> ii;
ii meeting[100001];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int a, b;
    for (int i = 1; i <= n; i ++){
        cin >> a >> b;
        meeting[i] = {a, b};
    }
}

bool cmp(ii a, ii b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(){
    input();
    sort(meeting + 1, meeting + n + 1, cmp);
    int cnt = 0, end = 0;
    for (int i = 1; i <= n; i ++){
        if (meeting[i].first < end) continue;
        cnt ++;
        end = meeting[i].second;
    }
    cout << cnt;
}