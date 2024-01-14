#include <iostream>
#include <algorithm>

using namespace std;

int a, b;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
}

int main(){
    input();
    int cnt = 0;
    int num = b;
    while (num > a){
        if (num / 10 && num % 10 == 1){
            num /= 10;
            cnt ++;
        }
        else if (num % 2 == 0){
            num /= 2;
            cnt ++;
        }
        else{
            break;
        }
    }
    num == a ? cout << cnt + 1 : cout << -1;
}