#include <iostream>
#include <algorithm>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M, K;
int A[202];
// bool here[202];
deque<int> robots;
int up, down, time;

void input(){
    fastio
    cin >> N >> K;
    M = 2 * N;
    for (int i = 0; i < M; ++ i){
        cin >> A[i];
    }
}

void show(){
    for (int i = 0; i < N; ++ i){
        cout << A[(up + i) % M] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= N; ++ i){
        cout << A[(down + i) % M] << ' ';
    }
    cout << '\n';
    cout << '\n';
}

void rotate(){
    up = (up + M - 1) % M;
    down = (down + M - 1) % M;
    if (robots.size() && robots.front() == down){
        robots.pop_front();
    }
}

void move_robot(){

    if (robots.empty()) return;

    // consider succesive down
    while (robots.size()){
        int pos = (robots[0] + 1) % M;
        if (A[pos] == 0) break;

        robots[0] = pos;
        if (--A[pos] == 0) K--;
        if (pos == down) robots.pop_front();
        else break;
    }

    // robots far from down
    for (int i = 1; i < robots.size(); ++ i){
        int pos = (robots[i] + 1) % M;
        if (A[pos] == 0 || robots[i - 1] == pos) continue;
        if (--A[pos] == 0) K--;
        robots[i] = pos;
    }
}

void put_robot(){
    if (A[up]){
        if(--A[up] == 0) K--;
        robots.push_back(up);
    }
}

void solve(){
    up = 0, down = N - 1;
    while (K > 0){
        rotate();
        // cout << "after rotate\n";
        // show();
        move_robot();
        // cout << "after move robot\n";
        // show();
        put_robot();
        // cout << "after put robot\n";
        // show();
        time ++;
    }
    cout << time;
}

int main(){
    input();
    solve();
    return 0;
}