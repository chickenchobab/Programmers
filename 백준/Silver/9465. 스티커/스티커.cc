#include <iostream>
#include <algorithm>

using namespace std;

int t, n;
long long sticker[3][100001];
long long d[3][100001];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=2;i++){
            for(int j=1;j<=n;j++){
                cin>>sticker[i][j];
            }
        }

        d[1][1]=sticker[1][1];
        d[2][1]=sticker[2][1];
        for(int i=2;i<=n;i++){
            d[1][i]=max(d[2][i-1], d[2][i-2])+sticker[1][i];
            d[2][i]=max(d[1][i-1], d[1][i-2])+sticker[2][i];
        }

        cout<<max(d[1][n],d[2][n])<<'\n';
        
    }
}