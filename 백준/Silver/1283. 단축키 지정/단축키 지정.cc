#include <iostream>
#include <algorithm>
#include <set>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
//set<char> s;
bool used[26];

void input(){
    fastio
    cin >> n;
    cin.ignore();
}

int select_key(string str, bool flag){

    bool start_of_word = 1;
    int index = -1;

    for (int j = 0; j < str.length(); j ++){
        if (((flag && start_of_word) || (!flag && isalpha(str[j]))) && !used[tolower(str[j]) - 'a']){
            used[tolower(str[j]) - 'a'] = 1;
            index = j;
            break;
        }
        if (!flag) continue;
        if (str[j] == ' ') start_of_word = 1;
        else start_of_word = 0;
    }

    return index;
}

void print(string str, int index){
    for (int i = 0; i < str.length(); i ++){
        if (i == index) cout << '[';
        cout << str[i];
        if (i == index) cout << ']';
    }
    cout << '\n';
}

void query(){
    string str;
    for (int i = 0; i < n; i ++){
        // cin.ignore();
        getline(cin, str);

        int index = select_key(str, 1);

        if (index != -1) {
            print(str, index);
            continue;
        }
        
        index = select_key(str, 0);
        print(str, index);
    }
}

int main(){
    input();
    query();
    return 0;
}