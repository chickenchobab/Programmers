#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];
int idx;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num;
    while (cin >> num) {
		arr[++ idx] = num;
	}
}

void post_order(int s, int e){
    
    if (s > e) return;
    int root = arr[s];
    int mid;
    for (mid = s + 1; mid <= idx && arr[mid] < root; mid ++);

    post_order(s + 1, mid - 1);
    post_order(mid, e);
    cout << root << '\n';
}

int main(){
    input();
    post_order(1, idx);
}