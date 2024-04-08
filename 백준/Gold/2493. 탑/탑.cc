#include<iostream>
#include<stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    stack<pair<int, int>> s;
    for(int i = 1; i <= N; i++) {
        int height;
        cin >> height;

        while(!s.empty()) {
            if(s.top().second > height) { // 현재 탑보다 높은 탑을 찾으면 그 탑의 번호 출력
                cout << s.top().first << " ";
                break;
            }
            s.pop(); // 현재 탑보다 낮은 탑은 스택에서 제거
        }

        if(s.empty()) { // 스택이 비어있으면 레이저 신호를 수신할 수 있는 탑이 없음을 의미
            cout << 0 << " ";
        }
        
        s.push(make_pair(i, height)); // 현재 탑 정보(번호, 높이)를 스택에 추가
    }

    return 0;
}