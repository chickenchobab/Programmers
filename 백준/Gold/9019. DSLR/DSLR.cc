#include <iostream>
#include <queue>
#include <string>

using namespace std;

int T, A, B;
int visited[10000];

int calculate (int op, int num){
    if (op == 0) return (num * 2) % 10000;
    if (op == 1) return num? num - 1 : 9999;
    if (op == 2) return num / 1000 + num % 1000 * 10;
    if (op == 3) return num / 10 + num % 10 * 1000;
}

string alpha (int op){
    if (op == 0) return "D";
    if (op == 1) return "S";
    if (op == 2) return "L";
    if (op == 3) return "R";
}

void bfs(){

    queue<pair<int, string>> q;
    visited[A] = 1;
    q.push({A, ""});

    while(q.size()){
        auto u = q.front();
        q.pop();

        if (u.first == B) {
            cout << u.second << '\n' ;
            return;
        }

        for (int d = 0 ; d < 4 ; d ++){
            int v = calculate(d, u.first);
            if (visited[v]) continue;
            visited[v] = 1;
            q.push({v, u.second + alpha(d)});
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    cin >> T;
    while (T --){
        cin >> A >> B;
        for (int i=0; i<=9999; i++) visited[i] = 0;
        bfs();
    }
    
}
