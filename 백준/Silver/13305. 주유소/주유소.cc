#include <iostream>
using namespace std;

int main()
{
    long long n, curd=0, totald=0, sum=0;
    cin>>n;

    long long *price = new long long[n];
    long long *dist = new long long[n];
    
    for(int i=0;i<n-1;i++){
        cin>>dist[i];
        totald+=dist[i];
    }
    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    int idx=0;
    while(curd<totald)
    {
        int i; long long pred=curd;
        for(i=idx; i<n-1 && price[idx]<=price[i] ; curd+=dist[i], sum+=dist[i]*price[idx], i++);
        idx=i;
    }

    cout<<sum<<endl;
    return 0;
}