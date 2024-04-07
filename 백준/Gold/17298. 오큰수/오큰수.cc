#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000001
using namespace std;

int n;
int arr[MAX], nge[MAX];
// deque<int> dq;
stack<int> st;

void input(){
    fastio
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> arr[i];
        // nge[i] = -1;
    }
}

void solve(){

    for (int i = n; i >= 1; i --){
        
        while (st.size() && st.top() <= arr[i]){
            st.pop();
        }
        if (st.size()) nge[i] = st.top();
        else nge[i] = -1;
        st.push(arr[i]);
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