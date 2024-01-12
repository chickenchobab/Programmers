#include <iostream>
#include <algorithm>

using namespace std;

int n, l;
int tick;
int pos[101], red[101], green[101];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l;
    for (int i = 1; i <= n; i ++){
        cin >> pos[i] >> red[i] >> green[i];
    }
}

int wait_time(int i){
    return max(red[i] - tick % (red[i] + green[i]), 0);
}

int main(){

    input();

    for (int i = 1; i <= n; i ++){
        tick += (pos[i] - pos[i - 1]);
        tick += wait_time(i);
    }
    tick += (l - pos[n]);

    cout << tick;

}