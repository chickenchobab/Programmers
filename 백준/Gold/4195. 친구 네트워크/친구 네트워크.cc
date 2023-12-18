#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int t, f;
int set[200001];

int find(int x){
    if(set[x]<0) return x;
    return (set[x]=find(set[x]));
}

void unite(int a,int b){
    int c1=find(a), c2=find(b);
    if(set[c1]<set[c2]){
        set[c1]+=set[c2];
        set[c2]=c1;
    }
    else {
        set[c2]+=set[c1];
        set[c1]=c2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>t;
    string n1,n2;
    while(t--){
        unordered_map<string, int> name;
        for(int i=1;i<=200000;i++){
            set[i]=-1;
        }
        cin>>f;
        while(f--){
            
            cin>>n1>>n2;
            name.insert({n1, name.size()+1});
            name.insert({n2, name.size()+1});
            
            if(find(name[n1])!=find(name[n2]))
                unite(name[n1], name[n2]);

            cout<<-set[find(name[n1])]<<'\n';
        }
    }
}