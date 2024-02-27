#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, c, m;
typedef tuple<int, int, int> box;
box boxes[10001];

int box_per_town[2002];

void input(){
    fastio
    cin >> n >> c >> m;
    int s, e, num;
    for (int i = 1; i <= m; i ++){
        cin >> s >> e >> num;
        boxes[i] = {s, e, num};
    }
}

void solve(){
    
    int load = 0;
    int sum = 0;

    sort(boxes + 1, boxes + m + 1);

    int s, e, num;
    for (int i = 1; i <= m; i ++){

        tie(s, e, num) = boxes[i];

        if (box_per_town[s]){
            load -= box_per_town[s];
            sum += box_per_town[s];
            box_per_town[s] = 0;
        }

        for (int j = n; j > e && num && load + num > c; j --){
            if (box_per_town[j] == 0)  continue;

            int l = min(num, box_per_town[j]);
            if (load + (num - l) < c) l = load + num - c;
            box_per_town[j] -= l;
            box_per_town[e] += l;
            num -= l;
        }
        
        int l = min(num, c - load);
        box_per_town[e] += l;
        load += l;
    }

    sum += load;

    cout << sum;
}

int main(){
    input();
    solve();
    return 0;
}