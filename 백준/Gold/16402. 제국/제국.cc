#include <iostream>
#include <string>
#include <map>

using namespace std;

int n,m,cnt;
int parent[501];
char name[501];
map<string, int> mp;

void init(){
    for(int i=1;i<=n;i++)
        parent[i]=i;
}

int find(int x){
    if(parent[x]==x) return x;
    else return parent[x]=find(parent[x]);
}

void merge(int a, int b, int order){
    int u=find(a);
    int v=find(b);
    if(order==1) {
        if(u==v) 
            parent[a]=a;
        parent[v]=a;
    }
    else{
        if(u==v)
            parent[b]=b;
        parent[u]=b;
    }

}

int main(){
    cin>>n>>m;
    cin.ignore();

    init();

    for(int i=1;i<=n;i++){
        string str;
        getline(cin, str);
        mp.insert({str.substr(11), mp.size()+1});
    }
    for(int i=1;i<=m;i++){
        char str1[21], str2[21];
        string s1, s2;
        int a,b,order;

        cin.getline(str1, 21, ',');
        cin.getline(str2, 21, ',');
        cin>>order;
        cin.ignore();
       
        s1=str1; s2=str2;
        a=mp[s1.substr(11)], b=mp[s2.substr(11)];
        merge(a,b,order);
    }
    
    for(int i=1;i<=n;i++){
        if(parent[i]==i) cnt++;
    }
    cout<<cnt<<'\n';
    for(auto i=mp.begin();i!=mp.end();i++){
        if(parent[i->second]==i->second) {
            cout<<"Kingdom of "<<i->first<<'\n';
        }
    }

}