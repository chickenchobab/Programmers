#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, char> bracketPair = {{')', '('}, {'}', '{'}, {']', '['}};

bool isRight(string s, int i){
    stack<char> st;
    int len = s.length();
    
    for (int j = i; j < i + len; ++j){
        char ch = s[j % len];
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else {
            if (st.empty() || bracketPair[ch] != st.top()) return false;
            st.pop();
        }
    }
    
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    int len = s.length();
    
    for (int i = 0; i < len; ++i){ 
        if (!(s[i] == '(' || s[i] == '{' || s[i] == '[')) continue;
        answer += isRight(s, i);
    }
    
    return answer;
}