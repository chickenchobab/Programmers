#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;

    stack<int> st;
    string str="";
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int cnt=0;

    for(int i=1;i<=n;i++){
        st.push(i); str+="+\n";
        if(!st.empty() && st.top()<arr[cnt]) 
            continue;
        while(!st.empty() && st.top()==arr[cnt]){
            st.pop(); str+="-\n"; cnt++;
        }
    }

    if(st.empty()) cout<<str;
    else cout<<"NO"<<'\n';

    delete arr;
    return 0;
}