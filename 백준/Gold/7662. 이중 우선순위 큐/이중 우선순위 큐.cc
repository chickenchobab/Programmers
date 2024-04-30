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

void update(bool reset){
    if (reset){
        while (maxq.size()) maxq.pop();
        while (minq.size()) minq.pop();
        return;
    }
    while (maxq.size() && popped[maxq.top().second]) 
        maxq.pop();
    while (minq.size() && popped[minq.top().second])
        minq.pop();
}

void solve(){
    int k; char c; int n;
    
    while (T --){
        int idx = 0;
        cin >> k;

        while (k --){
            cin >> c >> n;
            if (c == 'I'){ // insert a number
                idx ++;
                maxq.push({n, idx});
                minq.push({n, idx});
                popped[idx] = 0;
            }
            else {         // delete a number
                if (n == 1) {
                    if (maxq.empty()) continue;
                    popped[maxq.top().second] = 1;
                    maxq.pop();
                }
                else {
                    if (minq.empty()) continue;
                    popped[minq.top().second] = 1;
                    minq.pop();
                }
            }
            update(0);
        }
    
        if (maxq.size()) cout << maxq.top().first << ' ' << minq.top().first << '\n';
        else cout << "EMPTY\n";
        update(1);
    }
}

int main(){
    input();
    solve();
    return 0;
}