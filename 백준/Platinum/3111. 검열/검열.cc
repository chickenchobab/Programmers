#include <iostream>
#include <algorithm>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string w, t;
deque<char> dq_front, dq_back;
int s, e;

void input(){
    fastio
    cin >> w >> t;
}

void find_front() {
    int i;
    for (; s <= e; s ++) {
        dq_front.push_back(t[s]);
        if (dq_front.back() == w[w.length() - 1]){
            if (dq_front.size() < w.length()) continue;
            for (i = 0; i < w.length(); i ++) {
                if (dq_front[dq_front.size() - 1 - i] != w[w.length() - 1 - i]) break;
            }
            if (i != w.length()) continue;
            for (i = 0; i < w.length(); i ++) dq_front.pop_back();
            s ++;    
            // cout << "found front\n";
            return;
        }
    }
}

void find_back() {
    int i;
    for (; e >= s; e --) {
        dq_back.push_front(t[e]);
        if (dq_back.front() == w[0]){
            if (dq_back.size() < w.length()) continue;
            for (i = 0; i < w.length(); i ++) {
                if (dq_back[i] != w[i]) break;
            }
            if (i != w.length()) continue;
            for (i = 0; i < w.length(); i ++) dq_back.pop_front();
            e --;
            // cout << "found back\n";
            return;
        }
    }
}

string final_string() {
    string res = "";

    for(int i = 0; i < dq_front.size(); i ++) {
		res.push_back(dq_front[i]);
	}
	for(int i = 0; i < dq_back.size(); i ++) {
		res.push_back(dq_back[i]);
	}
    int i;
    while((i = res.find(w)) != string::npos) {
		res.erase(i, w.size());
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