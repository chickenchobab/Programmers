#include <iostream>
#include <algorithm>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string w, t;
deque<char> dq_front, dq_back;
int s, e, l;

void input(){
    fastio
    cin >> w >> t;
    l = w.length();
}

void find_front() {
    int i;
    for (; s <= e; s ++) {
        dq_front.push_back(t[s]);
        if (dq_front.back() == w[l - 1]){
            if (dq_front.size() < l) continue;
            for (i = 0; i < l; i ++) {
                if (dq_front[dq_front.size() - 1 - i] != w[l - 1 - i]) break; 
            }
            if (i == l) {
                while (i --) dq_front.pop_back();
                s ++;   
                return;
            }
        }
    }
}

void find_back() {
    int i;
    for (; e >= s; e --) {
        dq_back.push_front(t[e]);
        if (dq_back.front() == w[0]){
            if (dq_back.size() < l) continue;
            for (i = 0; i < l; i ++) {
                if (dq_back[i] != w[i]) break;
            }
            if (i == l) {
                while (i --) dq_back.pop_front();
                e --;
                return;
            }
        }
    }
}

string final_string() {
    string res = "";

    int i, j;
    for(i = 0; i < dq_front.size(); i ++) {
		res.push_back(dq_front[i]);
	}
	for(i = 0; i < dq_back.size(); i ++) {
		res.push_back(dq_back[i]);
        if (res.back() != w.back() || res.length() < l) continue;
        for (j = 0; j < l; j ++){
            if (res[res.size() - 1 - j] != w[l - 1 - j]) break;
        }
        if (j == l) {
            while (j --) res.pop_back();
        }
	}   

    return res;
}

void solve(){
    s = 0, e = t.length() - 1;
    while (s <= e){
        find_front();
        find_back();
    }

    cout << final_string();
}

int main(){
    input();
    solve();
    return 0;
}