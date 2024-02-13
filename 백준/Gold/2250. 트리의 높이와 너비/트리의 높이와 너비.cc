#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> edges[10001];

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
        edges[p].push_back(l);
        edges[p].push_back(r);

        ind[l] ++;
        ind[r] ++;

        min_idx[i] = 10001;
    }
}

void dfs(int cur, int lev){

    if (cur == -1) return;

    dfs(edges[cur][0], lev + 1);
    
    col ++;
    min_idx[lev] = min(min_idx[lev], col);
    max_idx[lev] = max(max_idx[lev], col);
    // cout << cur << ": " << col << '\n';

    dfs(edges[cur][1], lev + 1);
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