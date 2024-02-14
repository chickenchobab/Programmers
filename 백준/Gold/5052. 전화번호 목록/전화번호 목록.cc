#include <iostream>
#include <vector>
using namespace std;

int t;
int n;
struct Trie {
    Trie* ch[10];
    bool end;

    Trie(){
        end = false;
        for (int i = 0; i < 10; i ++) ch[i] = NULL;
    }

    ~Trie(){
        for (int i = 0; i < 10; i ++) if (ch[i]) delete ch[i];
    }

    void insert(const char* cur){
        if (!*cur) {
            this -> end = true;
            return;
        }
        int idx = *cur - '0';
        if (!ch[idx]) ch[idx] = new Trie;
        ch[idx] -> insert(cur + 1);
    }

    bool find(const char* cur){
        if (!*cur || end)  return true;
        int idx = *cur - '0';
        if (!ch[idx]) return false;
        return ch[idx] -> find(cur + 1);
    }
};

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
}

int solve(){
    cin >> n;

    int flag = 0;
    string str;
    Trie* root = new Trie();

    for (int i = 0; i < n; i ++){
        cin >> str;
        if (root -> find(str.c_str())) flag = 1;
        root -> insert(str.c_str());
    }

    delete root;

    return flag;
}

int main(){
    init();
    while (t --){
        solve() ? cout << "NO\n" : cout << "YES\n";
    }
    
}