#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> in(100001), post(100001);
// vector<int> g[100001];
int index[100001];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> in[i];
        index[in[i]] = i;
    }
    for (int i = 1; i <= n; i ++) 
        cin >> post[i];
}

void make_tree(int i, int j, int s, int e){

    if (i > j || s > e) return;

    int root = index[post[e]];
    int lsize = root - i;
    int rsize = j - root;

    cout << in[root] << ' ';
    make_tree(i, index[post[e]] - 1, s, s + lsize - 1); 
    make_tree(index[post[e]] + 1, j, s + lsize, e - 1);
    
    return;
}


int main(){

    input();
    make_tree(1, n, 1, n);
    return 0;
}