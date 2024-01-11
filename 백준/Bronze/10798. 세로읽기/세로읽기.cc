#include <iostream>
#include <algorithm>

using namespace std;

string arr[5];
int len;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 5; i ++){
        cin >> arr[i];
        len = max(len, (int)arr[i].length());
    }
}

int main(){
    
    input();

    int idx = 0;
    while (idx < len){
        for (int i = 0; i < 5; i ++){
            if (arr[i].length() - 1 < idx) continue;
            cout << arr[i][idx];
        }
        idx ++;
    }

    return 0;
}
