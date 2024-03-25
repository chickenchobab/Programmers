#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;


vector<int> cnt;
int n,c,map[26][26];

void dfs(int i, int j){
    if(map[i][j]!=0) return;
    if(i==0 || j==0 || i==n+1 || j==n+1) return;

    map[i][j]=1; c++;

    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i,j+1);
    dfs(i,j-1);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n; cin.ignore();

    for(int i=1;i<=n;i++){
        string str;
        getline(cin,str);
        for(int j=1;j<=n;j++){
            int tmp=str[j-1]-'0';
            
            if(!tmp) map[i][j]=-1;
            else map[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c=0;
            dfs(i,j);
            if(c) cnt.push_back(c);
        } 
    }

    sort(cnt.begin(), cnt.end());
    cout<<cnt.size()<<'\n';
    for(int i=0;i<cnt.size();i++){
        cout<<cnt[i]<<'\n';
    }

}