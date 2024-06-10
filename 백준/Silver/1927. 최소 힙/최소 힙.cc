#include <iostream>
#include <queue>
 
using namespace std;

int n;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(!tmp){
            if(pq.empty()) cout<<0<<'\n';
            else {cout<<pq.top()<<'\n'; pq.pop();}
        }
        else
            pq.push(tmp);
    }
}
