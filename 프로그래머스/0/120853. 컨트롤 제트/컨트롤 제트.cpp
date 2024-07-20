#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<int> st;
    
    int blank = -1;
    s += ' ';
    
    for (int i = 0; i < s.length(); ++i){
        if (s[i] == ' '){
            if (s[i - 1] != 'Z') st.push(stoi(s.substr(blank + 1, (i - blank))));
            blank = i;
        }
        else if (s[i] == 'Z'){
            if (st.size()) st.pop();
        }
    }
    
    while (st.size()) {
        answer += st.top();
        st.pop();
    }
    
    return answer;
}