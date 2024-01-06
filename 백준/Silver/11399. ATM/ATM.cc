#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,mul,sum=0;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0,mul=n;i<n;i++,mul--)
    {
        arr[i]*=mul;
        sum+=arr[i];
    }
    cout<<sum;

}