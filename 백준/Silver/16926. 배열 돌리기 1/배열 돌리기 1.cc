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

int start_index(int i, int j){
    int idx;
    int sub = (m - 1) * i - (n - 1) * j;
    int add = (m - 1) * i + (n - 1) * j - (n - 1) * (m - 1);
    if (add * sub < 0) {
        idx = min(j, (m - 1) - j);
    }
    else {
        idx = min(i, (n - 1) - i);
    }
    return idx;
}

int get_xst_num (int i, int j, int x){

    int cnt = x;
    int idx = start_index(i, j);
    int ei = (n - 1) - idx;
    int ej = (m - 1) - idx;
    while (cnt){
        int t;
        if (i > idx && j == idx) {
            t =  min(cnt, i - idx);
            i -= t; 
        }
        else if (i == ei && j > idx) {
            t = min(cnt, j - idx);
            j -= t;
        }
        else if (i < ei && j == ej) {
            t = min(cnt, ei - i);
            i += t;
        }
        else {
            t = min(cnt, ej - j);
            j += t;
        }
        cnt -= t;
    }
    return arr[i][j];
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
            //cout << arr[i][j] << ' ';
        }j --;
        for (i = idx + 1; i <= (n + 1) - idx; i ++){
            v[idx].push_back(arr[i][j]);
            //cout << arr[i][j] << ' ';
        }i --;
        for (j = j - 1; j >= idx; j --){
            v[idx].push_back(arr[i][j]);
            //cout << arr[i][j] << ' ';
        }j ++;
        for (i = i - 1; i > idx; i --){
            v[idx].push_back(arr[i][j]);
            // cout << arr[i][j] << ' ';
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