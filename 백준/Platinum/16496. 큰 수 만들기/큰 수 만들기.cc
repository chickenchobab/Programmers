#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int n;
int idx;
string list[1001];

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    cin.ignore();
    char ch;
    for (int i = 1; i <= n; i ++){
        string str = "";
        while (isdigit(ch = cin.get())) str = str + ch;
        list[i] = str;
    } 
}

bool cmp(string s1, string s2){

    string s12 = s1 + s2;
    string s21 = s2 + s1;
    return s21 < s12;

}

int main(){
    input();
    
    sort(list + 1, list + n + 1, cmp);

    if (list[1] == "0") { 
        cout << '0';
        return 0;
    }
    for (int i = 1; i <= n; i ++){
        cout << list[i];
    }
    
}