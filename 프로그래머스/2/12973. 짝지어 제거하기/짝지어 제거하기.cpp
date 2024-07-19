#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    // bool answer;
    stack<char> st;
    
    for (int i = 0; i < s.length(); ++i){
        char ch = s[i];
        if (st.empty() || st.top() != ch){
            st.push(ch);
        }
        else {
            st.pop();
        }
    }

    return st.empty();
}