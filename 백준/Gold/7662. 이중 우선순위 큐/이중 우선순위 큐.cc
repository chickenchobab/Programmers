#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int T;
typedef pair<int, int> p;


void input(){
    fastio
    cin >> T;
}

void solve(){
    int k; char c; int n;
    
    while (T --){
        priority_queue<p> maxq; 
        priority_queue<p, vector<p>, greater<p>> minq;
        bool popped[1000001] = {0,};
        cin >> k;

        int idx = 0;
        while (k --){
            cin >> c >> n;
            if (c == 'I'){   // insert a number
                idx ++;
                maxq.push({n, idx});
                minq.push({n, idx});
            }
            else {           // delete a number
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
            while (maxq.size() && popped[maxq.top().second]) maxq.pop();
            while (minq.size() && popped[minq.top().second]) minq.pop();
        }
        
        if (maxq.size()) cout << maxq.top().first << ' ' << minq.top().first << '\n';
        else cout << "EMPTY\n";
    }
}

int main(){
    input();
    solve();
    return 0;
}