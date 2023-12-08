#include <iostream>

using namespace std;

int n;
int edge[101][101];

int main(){
    cin >> n;
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> edge[i][j];
        }
    }
    for (int s=1; s<=n; s++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){

                if (edge[i][j] == 1) continue;
                if (i == s || j == s) continue;
                if (edge[i][s] == 0 || edge[s][j] == 0) continue;
                edge[i][j] = 1;
            }
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout << edge[i][j] << ' ';
        }
        cout << '\n';
    }
}