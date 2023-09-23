#include <iostream>
#include <algorithm>
#define MAX 1000001

using namespace std;

int num;
int arr[MAX]={0,};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>num;
    

    int n=num;
    while(n){
        if(n%3==0) {
            if(arr[n/3]) arr[n/3]=min(arr[n]+1,arr[n/3]);
            else arr[n/3]=arr[n]+1;
        }

        if(n%2==0) {
            if(arr[n/2]) arr[n/2]=min(arr[n]+1,arr[n/2]);
            else arr[n/2]=arr[n]+1;
        }

        if(arr[n-1]) arr[n-1]=min(arr[n]+1,arr[n-1]);
        else arr[n-1]=arr[n]+1;
        n--;
    }
    

    cout<<arr[1];

}