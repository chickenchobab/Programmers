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

int pop(){
    int i, child;
    int front, back;

    front=heap[1];
    back=heap[s--];
    for(i =1; i*2<=s; i=child){
        child=i*2;
        if(child!=s && heap[child+1]>heap[child])
            child++;
        if(back>heap[child])
            heap[i]=heap[child];
        else
            back;
    }
    heap[i]=back;
    return front;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        push(i);
    }
    for(int i=1;i<=n;i++){
        cout<<heap[i]<<' ';
    }

    
}