#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int T;
typedef pair<int, int> p;
priority_queue<p> maxq; 
priority_queue<p, vector<p>, greater<p>> minq;
bool popped[1000001];

void input(){
    fastio
    cin >> T;
}

void solve(){
    int k; char c; int n;
    
    while (T --){
        cin >> k;

        int idx = 0;
        while (k --){
            cin >> c >> n;
            if (c == 'I'){
                idx ++;
                maxq.push({n, idx});
                minq.push({n, idx});
                popped[idx] = 0;
            }
            else {
                if (n == 1) {
                    while (maxq.size() && popped[maxq.top().second]) maxq.pop();
                    if (maxq.empty()) continue;
                    popped[maxq.top().second] = 1;
                    maxq.pop();
                }
                else {
                    while (minq.size() && popped[minq.top().second]) minq.pop();
                    if (minq.empty()) continue;
                    popped[minq.top().second] = 1;
                    minq.pop();
                }
            }
        }
        while (maxq.size() && popped[maxq.top().second]) maxq.pop();
        while (minq.size() && popped[minq.top().second]) minq.pop();

        if (maxq.size()) cout << maxq.top().first << ' ' << minq.top().first << '\n';
        else cout << "EMPTY\n";

        while (maxq.size()) maxq.pop();
        while (minq.size()) minq.pop();
    }
}

int main(){
    input();
    solve();
    return 0;
}