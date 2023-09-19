#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long d[501][502];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;

    int tmp;
    for(int i=1; i<=n; i++){
        for(int j=1;j<=i;j++){
            cin>>tmp;
            d[i][j]=max(d[i-1][j-1],d[i-1][j])+tmp;
        }
    }
    int m=0;
    for(int i=1;i<=n;i++){
        if(m<d[n][i]) m=d[n][i];
    }

    cout<<m;

}