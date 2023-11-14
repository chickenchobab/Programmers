#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

typedef pair<int, int> p;
int n,m,a,b,arr[MAX]; 
p tree[4*MAX];

p init(int s, int e, int node){
    if(s==e) return tree[node]={arr[s],arr[s]};
    int mid=(s+e)/2;
    init(s,mid,2*node);
    init(mid+1,e,2*node+1);

    int x=max(tree[2*node].first, tree[2*node+1].first);
    int y=min(tree[2*node].second, tree[2*node+1].second);
    return tree[node]={x,y};
}

int big(int s, int e, int node, int l, int r){
    if(r<s || l>e) return 0;
    if(l<=s && r>=e) return tree[node].first;

    int mid=(s+e)/2; 

    return max(big(s,mid,2*node,l,r),big(mid+1, e,2*node+1,l,r));
}

int small(int s, int e, int node, int l, int r){
    if(r<s || l>e) return 1000000000;
    if(l<=s && r>=e) return tree[node].second;

    int mid=(s+e)/2; 

    return min(small(s,mid,2*node,l,r),small(mid+1,e,2*node+1,l,r));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    init(1,n,1);
    // cout<<"\n\n";
    // for(int i=1;i<=4*n;i++){
    //     cout<<tree[i].first<<' '<<tree[i].second<<'\n';
    // }
    // cout<<"\n\n";
    while(m--){
        cin>>a>>b;
        cout<<small(1,n,1,a,b)<<' '<<big(1,n,1,a,b)<<'\n';
    }

}