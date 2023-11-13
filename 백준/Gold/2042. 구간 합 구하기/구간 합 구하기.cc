#include <iostream>
#include <vector>

#define MAX 1000001

using namespace std;

long long n,m,k,a,b,c;
long long arr[MAX], tree[4*MAX];

long long init(int s, int e, int node){
    if(s==e) return tree[node]=arr[s];
    int mid=(s+e)/2;
    return tree[node]=init(s,mid,2*node)+init(mid+1,e,2*node+1);
}

long long sum(int s, int e, int node, int l, int r){
    if(r<s || l>e) return 0;
    if(l<=s && r>=e) return tree[node];

    int mid=(s+e)/2; 

    return sum(s,mid,2*node,l,r)+sum(mid+1, e,2*node+1,l,r);
}

void update(int s, int e, int node, int idx, long long gap){
    if(idx<s || idx>e) return;
    tree[node]+=gap;
    
    if(s==e) return;
    int mid = (s+e)/2;

    update(s,mid,2*node,idx,gap);
    update(mid+1, e, 2*node+1, idx, gap);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    init(1,n,1);
    int t=m+k;
    while(t--){
        cin>>a>>b>>c;
        if(a==1){
            update(1,n,1,b,c-arr[b]);
            arr[b]=c;
        }
        else{
            long long ans=sum(1,n,1,b,c);
            cout<<ans<<'\n';
        }
    }

}