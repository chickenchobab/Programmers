#include <iostream>

using namespace std;

int n,s;
int heap[100001];

void push(int x){
    int i;
    int tmp=heap[s];
    
    for(i=s; heap[i/2]<x && i>1; i/=2){
        heap[i]=heap[i/2];
    }
    heap[s+1]=tmp; 

    if(s)
        heap[i]=x;
    else
        heap[1]=x;
    s++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        push(i);
    }
    for(int i=1;i<=n;i++){
        cout<<heap[i]<<' ';
    }

    
}