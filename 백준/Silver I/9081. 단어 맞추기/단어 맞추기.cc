#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int t;

void input(){
    fastio
    cin >> t;
}

void query(){
    string str;
    while (t --){
        cin >> str;
        int len = str.length();
        for (int i = len - 2; i >= 0; i --){
            if (str[i] >= str[i + 1]) continue; // 내림 차순이 처음으로 깨지는 부분을 찾는다

            int flag = 0;
            for (int j = len - 1; j > i && flag == 0; j --){
                if (str[i] >= str[j]) continue; // 정렬 필요한 문자 중에서 i보다 크면서 가장 작은 j를 찾는다
                flag = 1;
                // cout << str[i] << ' ' << str[j] << " swapped\n";
                swap(str[i], str[j]);
                sort(str.begin() + i + 1, str.end());
            }
            if (flag) break;
        }
        cout << str << '\n';
    }
}

int main(){
    input();
    query();
}