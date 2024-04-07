#include <iostream>
#include <algorithm>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000001
using namespace std;

int n;
int arr[MAX], nge[MAX];
deque<int> dq;

void input(){
    fastio
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> arr[i];
        nge[i] = -1;
    }
}

void solve(){

    for (int i = 1; i <= n; i ++){
        
        while (dq.size() && arr[dq.back()] < arr[i]){
            nge[dq.back()] = arr[i];
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = 1; i <= n; i ++){
        cout << nge[i] << ' ';
    }
}

int main(){
    input();
    solve();
    return 0;
}