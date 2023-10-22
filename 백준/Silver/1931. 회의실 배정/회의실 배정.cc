#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int>& a, pair<int,int>& b)
{
    if(a.second==b.second) 
        return a.first<b.first;
    return a.second<b.second;
}

int main()
{
    cin.tie(nullptr);   
    ios_base::sync_with_stdio(false);

    vector<pair<int,int>> v;
    int n,a,b,cnt=1; 
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),cmp);

    for(int i=1,end=v[0].second; i<n; i++){
        if(end>v[i].first) continue;
        end=v[i].second;
        cnt++;
    }
    
    cout<<cnt<<endl;
    
}
