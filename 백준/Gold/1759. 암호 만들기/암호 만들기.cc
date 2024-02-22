#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l,c;
int cnt1, cnt2;
char arr[16];
vector<char> str;

void dfs(int u){
    if(str.size()==l){
        if(cnt1>0 && cnt2>1){
            for(char ch:str) cout<<ch;
            cout<<'\n';
        }
       return;
    }
    for(int v=u; v<=c;v++){
        char tmp=arr[v];
        str.push_back(tmp);
        if(tmp=='a' || tmp=='e' || tmp=='i' || tmp=='o' || tmp=='u')
            cnt1++;
        else cnt2++;
        dfs(v+1);
        tmp=str.back();
        str.pop_back();
        if(tmp=='a' || tmp=='e' || tmp=='i' || tmp=='o' || tmp=='u')
            cnt1--;
        else cnt2--;
    }       
    
}

int main(){
    cin>>l>>c;
    //int tmp;
    for(int i=1;i<=c;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+c+1);
    dfs(1);
    
}