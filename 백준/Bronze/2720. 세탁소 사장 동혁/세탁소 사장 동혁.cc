#include <iostream>

using namespace std;

int t;
int coin[4] = {25, 10, 5, 1};

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
}

int main(){
    input();

    int c;
    while(t --){

        cin >> c;
        for (int i = 0; i < 4; i ++){
            cout << c / coin[i] << ' ';
            c %= coin[i];
        }
        cout << '\n';
        
    }
}