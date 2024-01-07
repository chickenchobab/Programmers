#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> pq;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i ++){
        cin >> tmp;
        pq.push(tmp);
    }
}

int main(){

    input();

    long long sum = 0;
    long long a, b;
    while (pq.size() >= 2){
        a = pq.top(); 
        pq.pop();
        b = pq.top();
        pq.pop();
        sum += (a + b);
        if (pq.empty()) break;
        pq.push(a + b);
    }

    cout << sum;
}