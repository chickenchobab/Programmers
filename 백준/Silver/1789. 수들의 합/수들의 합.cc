#include <iostream>

using namespace std;

typedef long long ll;
ll n, s;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;

}

int main(){

    input();
    
    int idx = 1;
    while(s >= idx){
        s -= idx ++;
    }

    cout << idx - 1;
}