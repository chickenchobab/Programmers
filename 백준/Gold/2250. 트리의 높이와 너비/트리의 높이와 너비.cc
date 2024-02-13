#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int tree[10001][2];

int min_idx[10001], max_idx[10001], ind[10001];
int col;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    int p, l, r;
    for (int i = 1; i <= n; i ++){
        cin >> p >> l >> r;
        tree[p][0] = l;
        tree[p][1] = r;

        ind[l] ++;
        ind[r] ++;
    }
}

void dfs(int cur, int lev){

    if (cur == -1) return;

    dfs(tree[cur][0], lev + 1);
    
    col ++;
    if (min_idx[lev] == 0) min_idx[lev] = max_idx[lev] = col;
    else max_idx[lev] = col;

    dfs(tree[cur][1], lev + 1);
}

int main(){
    input();

    int start;
    for (start = 1; ind[start]; start ++);
        
    dfs(start, 1);

    int width = 1, level = 1;
    for (int i = 1; i <= n && min_idx[i] != 10001 && max_idx[i]; i ++){
        int res = max_idx[i] - min_idx[i] + 1;
        if (width < res){
            width = res;
            level = i;
        }
    }
    cout << level << " " << width;
}