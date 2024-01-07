#include <iostream>
#include <algorithm>

using namespace std;


typedef pair<int, int> p;
int n;
int a[51],b[51];
int sum;

int main(){
    cin>>n;

    int tmp;
    for(int i=1;i<=n;i++) {
        cin>>tmp;
        a[i]=tmp;
    }
    for(int i=1;i<=n;i++) {
        cin>>tmp;
        b[i]=tmp;
    }

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    for(int i=1;i<=n;i++){
        sum+=(a[i]*b[n-i+1]);
    }
    cout<<sum;
}