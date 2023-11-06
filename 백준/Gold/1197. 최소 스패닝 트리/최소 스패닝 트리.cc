#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

long long cnt;
int v,e,a,b,c;
int arr[10001];
tuple<int,int,int> edge[100000];

int find(int x){
    while(arr[x]>0) x=arr[x];
    return x;
}

void unite(int a, int b){
    int c1=find(a);
    int c2=find(b);
    if(c1<c2)
        arr[c2]=c1;
    else
    {
        if(arr[c1]==arr[c2])
            arr[c1]--;
        arr[c1]=c2;
    }  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>v>>e;
    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        edge[i]={c,a,b};
    }
    sort(edge, edge+e);

    for(int i=0;i<e;i++){
        a=get<1>(edge[i]);
        b=get<2>(edge[i]);
        if(find(a)==find(b)) continue;
        unite(a,b);
        cnt+=get<0>(edge[i]);
    }

    cout<<cnt;

}