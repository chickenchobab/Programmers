#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grade[500005];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n; 
    for (int i = 1; i <= n; i ++){
        cin >> grade[i];
    }
}

int main(){

    long long sum = 0;
    input();

    sort(grade + 1, grade + n + 1);
    for (int i = 1; i <= n; i ++){
        sum += abs(grade[i] - i);
    }
    cout << sum;
}