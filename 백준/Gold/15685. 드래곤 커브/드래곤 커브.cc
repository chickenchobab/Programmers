#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define showsize 9
using namespace std;

int n;
int di[] = {0, -1, 0, 1}, dj[] = {1, 0, -1, 0};
bool visited[102][102];
vector<int> direction;

void input(){
    fastio
    cin >> n;
}

void make_dragon_curve(int i, int j, int cnt){
    if (cnt == -1) return;

    int stride = direction.size();
    int ni = i, nj = j;

    for (int s = stride / 2; s < stride; s ++){
        ni = ni + di[direction[s]];
        nj = nj + dj[direction[s]];
        visited[ni][nj] = 1;
    }
    for (int s = stride; s > 0; s --){
        direction.push_back((direction[s - 1] + 1) % 4);
    }

    make_dragon_curve(ni, nj, cnt - 1);
}

int count_rectangle(){
    int ans = 0;
    for (int i = 0; i < 100; i ++){
        for (int j = 0; j < 100; j ++){
            if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1]) ans ++;
        }
    }
    return ans;
}

void solve(){
    int i, j, d, g;

    while (n --){
        cin >> j >> i >> d >> g;
        visited[i][j] = 1;
        direction.push_back(d);
        make_dragon_curve(i, j, g);
        direction.clear();
    }
    
    cout << count_rectangle();
}

void show(){
    cout << '\n';
    for (int i = 0; i < showsize; i ++){
        for (int j = 0; j < showsize; j ++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    input();
    solve();
    //show();
    return 0;
}