#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
typedef pair<int, int> l;
l lectures[200002];
priority_queue<int, vector<int>, greater<int>> pq;

void input(){
    fastio
    cin >> n;
    int s, t;
    for (int i = 0; i < n; i ++){
        cin >> s >> t;
        lectures[i] = {s, t};
    }
}

void solve(){
    sort(lectures, lectures + n);
    pq.push(lectures[0].second);
    for (int i = 1; i < n; i ++){
        if(lectures[i].first >= pq.top()){
            pq.pop();
        }
        pq.push(lectures[i].second);
    }
    cout << pq.size();
}

int main(){
    input();
    solve();
    return 0;
}