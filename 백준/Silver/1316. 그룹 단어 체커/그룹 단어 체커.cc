#include <iostream>

using namespace std;

int n;

void init(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
}

int main(){
    
    init();

    int cnt = 0;
    string str;
    for (int i = 1; i <= n; i ++){
        cin >> str;
        int group = 1;
        int alpha[3 * 3 * 3] = {0,};
        alpha[str[0] - 'a'] = 1;
        for (int j = 1; j < str.length(); j ++){
            if (str[j] != str[j - 1] && alpha[str[j] - 'a']) {
                group = 0;
                break;
            }
            alpha[str[j] - 'a'] = 1;
        }
        if (group) cnt ++;
    }
    cout << cnt;
}