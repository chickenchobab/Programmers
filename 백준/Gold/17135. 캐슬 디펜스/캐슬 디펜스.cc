#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M, D, siz;
typedef struct ENEMY{
    int r, c, status;
}enemy;
vector<enemy> squad, base;
int archer[3];
int ans, score, finished;

void input(){
    fastio
    cin >> N >> M >> D;
    int num;
    for (int i = 1; i <= N; ++ i){
        for (int j = 1; j <= M; ++ j){
            cin >> num;
            if (num) base.push_back({i, j, 1});
        }
    }
    siz = base.size();
}

void reset(){
    for (int e = 0; e < siz; ++ e)
        squad[e] = base[e];
    score = finished = 0;
}

void kill(int row, int col){
    if (finished) return;

    int dist = N + M, idx = -1, active = 0;

    for (int e = 0; e < siz; ++ e){
        if (squad[e].status == 0) continue; // allow kill already killed(-1)
        active ++;
        int d = abs(squad[e].r - row) + abs(squad[e].c - col);
        if (d > D) continue;

        if (dist > d){ // find the closest enemy
            dist = d;
            idx = e;
        }
    }
    if (active == 0) finished = 1;
    else if (idx != -1 && squad[idx].status == 1){
        score ++; // score increases if newly killed(1)
        squad[idx].status = -1;
    }
}

void check(int row){
    if (finished) return;

    int active = 0;
    for (int e = 0; e < siz; ++ e){
        if (squad[e].status == -1 || squad[e].r + 1 == row) squad[e].status = 0;
        if (squad[e].status == 0) continue;
        
        active ++;
    }
    if (active == 0) finished = 1;
}

void show(){
    bool map[N + 1][M + 1] = {0,};

    for (int e = 0; e < siz; ++ e){
        if (squad[e].status == 0) continue;
        int r = squad[e].r;
        int c = squad[e].c;
        map[r][c] = 1;
    }

    for (int i = 1; i <= N; ++ i){
        for (int j = 1; j <= M; ++ j){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "score = " << score << "\n";
    for (int i = 0; i < 3; i ++){
        cout << archer[i] << ' ';
    }
    cout << "\n\n";
}

void fight(){
    for (int row = N + 1; row > 0; row --){
        for (int a = 0; a < 3; a ++){
            kill(row, archer[a]);
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
        archer[cnt] = nxt;
        dispose(nxt, cnt + 1);
        // archer[cnt] = 0;
    }
}

bool cmp(enemy a, enemy b){
    if (a.c == b.c) return a.r > b.r;
    return a.c < b.c;
}

void solve(){
    sort(base.begin(), base.end(), cmp);
    for (enemy e : base) 
        squad.push_back(e);

    for (int st = 1; st <= M - 2; ++ st){
        archer[0] = st;
        dispose(st, 1);
        // archer[0] = 0;
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}