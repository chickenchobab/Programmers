#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int R, C, M;
int sum;
typedef struct SHARK{
    int r, c, spd, dir, siz;
    bool alive;
}shark;
int map[101][101];
int di[] = {0, -1, 1, 0, 0}, dj[] = {0, 0, 0, 1, -1};
vector<shark> sharks;

void input(){
    fastio
    cin >> R >> C >> M;
    int r, c, s, d, z;
    sharks.push_back({0, 0, 0, 0, 0});
    for (int i = 1; i <= M; i ++){
        cin >> r >> c >> s >> d >> z;
        map[r][c] = i;
        sharks.push_back({r, c, s, d, z, 1});
    }
}

void move(int idx){
    shark s = sharks[idx];
    int dist = s.spd;
    while (dist){
        int nr = s.r + dist * di[s.dir];
        int nc = s.c + dist * dj[s.dir];
        if (nr > R) {
            dist -= (R - s.r);
            nr = R;
            s.dir = 1;
        }
        else if (nr < 1){
            dist -= (s.r - 1);
            nr = 1;
            s.dir = 2;
        }
        else if (nc > C){
            dist -= (C - s.c);
            nc = C;
            s.dir = 4;
        }
        else if (nc < 1){
            dist -= (s.c - 1);
            nc = 1;
            s.dir = 3;
        }
        else {
            dist = 0;
        }
        s.r = nr;
        s.c = nc;
    }
    sharks[idx] = s;
}

void conquer(int idx){
    shark s = sharks[idx];
    if (map[s.r][s.c]){
        if (sharks[map[s.r][s.c]].siz > s.siz) sharks[idx].alive = 0;
        else {
            sharks[map[s.r][s.c]].alive = 0;
            map[s.r][s.c] = idx;
        }
    }
    else map[s.r][s.c] = idx;
}


void rearange(){

    for (int i = 1; i <= R; i ++){
        for (int j = 1; j <= C; j ++){
            map[i][j] = 0;
        }
    }

    for (int idx = 1; idx <= M; idx ++){
        if (sharks[idx].alive == 0) {
            continue;
        }
        move(idx);
        conquer(idx);
    }
}

void hunt(int j){
    for (int i = 1; i <= R; i ++){
        if (map[i][j]){
            sum += sharks[map[i][j]].siz;
            sharks[map[i][j]].alive = 0;
            map[i][j] = 0;
            break;
        }
    }
}

void solve(){
    for (int j = 1; j <= C; j ++){
        hunt(j);
        rearange();
    }
    cout << sum;
}

int main(){
    input();
    solve();
    return 0;
}