#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M, D, siz;
typedef struct ENEMY{
    int r, c, status;
}enemy;
vector<enemy> squad;
int arcpos[3];
int ans, score;

void input(){
    fastio
    cin >> N >> M >> D;
    int num;
    for (int i = 1; i <= N; ++ i){
        for (int j = 1; j <= M; ++ j){
            cin >> num;
            if (num) squad.push_back({i, j, 1});
        }
    }
    siz = squad.size();
}

void reset(){
    score = 0;
    for (int e = 0; e < siz; ++ e) 
        squad[e].status = 1;
}

void kill(int row, int col){
    int dist = N + M, idx = -1;

    for (int e = 0; e < siz; ++ e){
        if (squad[e].status == 0) continue; // allow kill already killed(-1)
        int d = abs(squad[e].r - row) + abs(squad[e].c - col);
        if (d > D) continue;

        if (dist > d){ // find the closest enemy
            dist = d;
            idx = e;
        }
    }
    
    if (idx != -1 && squad[idx].status == 1){
        score ++; // score increases if newly killed(1)
        squad[idx].status = -1;
    }
}

void check(int row){
    for (int e = 0; e < siz; ++ e){
        // change the status of who newly died or entered
        if (squad[e].status == -1 || squad[e].r + 1 == row) squad[e].status = 0;
        if (squad[e].status == 0) continue;
    }
}

void fight(){
    for (int row = N + 1; row > 0; row --){
        for (int a = 0; a < 3; a ++){
            kill(row, arcpos[a]);
        }
        check(row);
        // show();
    }
    ans = max(ans, score);
}

void dispose(int cur, int cnt){
    if (cnt == 3) {
        fight();
        reset();
        return;
    }
    for (int nxt = cur + 1; nxt <= M; ++ nxt){
        arcpos[cnt] = nxt;
        dispose(nxt, cnt + 1);
        // arcpos[cnt] = 0;
    }
}

bool cmp(enemy a, enemy b){
    if (a.c == b.c) return a.r > b.r;
    return a.c < b.c;
}

void solve(){
    sort(squad.begin(), squad.end(), cmp);

    for (int st = 1; st <= M - 2; ++ st){
        arcpos[0] = st;
        dispose(st, 1);
        // arcpos[0] = 0;
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}