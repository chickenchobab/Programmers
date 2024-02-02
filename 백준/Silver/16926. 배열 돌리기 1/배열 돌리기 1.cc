#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, r;
int arr[301][301];
typedef pair<int, int> p;


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

int main(){
    input();

    vector<int> v[min(n, m) / 2 + 1];

    int i, j, idx;
    for (idx = 1; idx <= min(n, m) / 2; idx ++){
        i = idx;
        v[idx].push_back(arr[idx][idx]);
        for (j = idx + 1; j <= (m + 1) - idx; j ++){
            v[idx].push_back(arr[i][j]);
        }j --;
        for (i = idx + 1; i <= (n + 1) - idx; i ++){
            v[idx].push_back(arr[i][j]);
        }i --;
        for (j = j - 1; j >= idx; j --){
            v[idx].push_back(arr[i][j]);
        }j ++;
        for (i = i - 1; i > idx; i --){
            v[idx].push_back(arr[i][j]);
        }i ++;
    }

    int arr_idx;
    for (idx = 1; idx <= min(n, m) / 2; idx ++){
        arr_idx = 0;
        i = idx;
        arr[idx][idx] = v[idx][(arr_idx ++ + r) % v[idx].size()];
        for (j = idx + 1; j <= (m + 1) - idx; j ++){
            arr[i][j] = v[idx][(arr_idx ++ + r) % v[idx].size()];
        }j --;
        for (i = idx + 1; i <= (n + 1) - idx; i ++){
            arr[i][j] = v[idx][(arr_idx ++ + r) % v[idx].size()];
        }i --;
        for (j = j - 1; j >= idx; j --){
            arr[i][j] = v[idx][(arr_idx ++ + r) % v[idx].size()];
        }j ++;
        for (i = i - 1; i > idx; i --){
            arr[i][j] = v[idx][(arr_idx ++ + r) % v[idx].size()];
        }i ++;
    }


    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}