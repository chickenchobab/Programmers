#include <iostream>

using namespace std;

int n,m,a,b;
int parent[1000001];

void init(){
    for(int i=0; i<=n; i++)
        parent[i]=-1;
}

int find(int x){
    if(parent[x]<0) return x;
    else return parent[x]=find(parent[x]);
}

void merge(int a, int b){
    a=find(a);
    b=find(b);
    if(parent[a]<parent[b])
        parent[b]=a;
    else{
        if(parent[a]==parent[b])
            parent[b]--;
        parent[a]=b;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    init();
    int order;
    for(int i=1;i<=m;i++){
        cin>>order>>a>>b;
        if(order==0){
            if(find(a)==find(b)) continue;
            merge(a,b);
        }
        else{
            if(find(a)==find(b)) cout<<"yes\n";
            else cout<<"no\n";
        }
    }

}