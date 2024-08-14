#include <string>
#include <vector>
#include <stack>
#include <algorithm>
// #include <sstream>

using namespace std;

vector<int> solution(string s) {
    stack<char> st;
    vector<int> counts(100001, 0);
    vector<int> numbers;
    
    for (char &ch : s){
        if (ch == '}'){
            while (st.size() && st.top() != '{'){
                int num = 0;
                int digit = 1;
                while (st.size() && isdigit(st.top())){
                    num += (st.top() - '0') * digit;
                    digit *= 10;
                    st.pop();
                }
                if (st.top() == ',') st.pop();
                if (!num) continue;
                
                if (!counts[num]) numbers.push_back(num);
                counts[num]++;
            }
            st.pop();
        }
        else st.push(ch);
    }
    
    sort(numbers.begin(), numbers.end(), [counts](int &a, int &b){
        return counts[a] > counts[b];
    });
    return numbers;
}