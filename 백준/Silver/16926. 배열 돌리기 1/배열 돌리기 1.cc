#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, r;
int arr[301][301];
vector<int> skin;


void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> arr[i][j];
        }
    } 
}

void peel(int idx){

    int i, j;
    skin.clear();

    i = idx;
    for (j = idx; j <= (m + 1) - idx; j ++){
        skin.push_back(arr[i][j]);
    }j --;
    for (i = idx + 1; i <= (n + 1) - idx; i ++){
        skin.push_back(arr[i][j]);
    }i --;
    for (j = j - 1; j >= idx; j --){
        skin.push_back(arr[i][j]);
    }j ++;
    for (i = i - 1; i > idx; i --){
        skin.push_back(arr[i][j]);
    }i ++;
    
}

void rotate(int idx){
    
    int i, j;
    int arr_idx = 0;
    int skin_size = skin.size();

    i = idx;
    for (j = idx; j <= (m + 1) - idx; j ++, arr_idx ++){
        arr[i][j] = skin[(arr_idx + r) % skin_size];
    }j --;
    for (i = idx + 1; i <= (n + 1) - idx; i ++, arr_idx ++){
        arr[i][j] = skin[(arr_idx + r) % skin_size];
    }i --;
    for (j = j - 1; j >= idx; j --, arr_idx ++){
        arr[i][j] = skin[(arr_idx + r) % skin_size];
    }j ++;
    for (i = i - 1; i > idx; i --, arr_idx ++){
        arr[i][j] = skin[(arr_idx + r) % skin_size];
    }i ++;
}


int main(){
    input();

    for (int idx = 1; idx <= min(m, n) / 2; idx ++){
        peel(idx);
        rotate(idx);
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}