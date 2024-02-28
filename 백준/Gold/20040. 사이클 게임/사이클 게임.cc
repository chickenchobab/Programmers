#include <iostream>
#include <vector>

using namespace std;

int n,m,a,b,turn;
vector<int> set;

int find(int x){
    if(set[x]<0) return x;
    return (set[x]=find(set[x]));
}

void unite(int a, int b){
    int c1=find(a), c2=find(b);
    if(set[c1]<set[c2])
        set[c2]=c1;
    else{
        if(set[c1]==set[c2])
            set[c2]--;
        set[c1]=c2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    
    set.assign(n,0);
    for(int i=0;i<n;i++){
        set[i]=-1;
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        if(find(a)==find(b)){
            turn=i; break;
        }
        unite(a,b);
        
    }
    cout<<turn;
}