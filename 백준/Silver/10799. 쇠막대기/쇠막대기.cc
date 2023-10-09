#include <iostream>
#include <stack>

using namespace std;

stack<char> st;
int cnt,sum;

int main(){

    char ch;
    while((ch=cin.get())!='\n'){
        st.push(ch);
    }

    while(!st.empty()){
        if(st.top()==')'){
            cnt++;
            st.pop();
            if(st.top()=='('){
                cnt--;
                st.pop();
                sum+=cnt;
            }
        }
        else{
            cnt--;
            st.pop();
            sum++;
        }
    }

    cout<<sum;
    return 0;

}