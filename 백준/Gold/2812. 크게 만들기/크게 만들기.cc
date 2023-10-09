#include <iostream>
#include <vector>

using namespace std;

int n,k;
char ch;
vector<char> v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;
    int cnt=k;
    for(int i=1;i<=n;i++){
        cin>>ch;
        while(cnt && !v.empty() && ch>v.back()){
            v.pop_back();
            cnt--;
        }
        if(v.size()<n-k)
            v.push_back(ch);
    }
    for(char ch:v){
        cout<<ch;
    }
}