#include <iostream>
#include <vector>
#define INF 100000000

using namespace std;

int n, m, a, b, c;
int edge[101][101], pi[101][101];
vector<int> printer;

void find_path(int i, int j){
    if (i == j) 
        printer.push_back(i);
    else if (edge[i][j] == INF)
        printer.clear();
    else{
        find_path(i, pi[i][j]);
        printer.push_back(j);
    }
}

void print_path(int i, int j){
    if (i == j) printer.clear();
    cout << printer.size() << ' ';
    if (printer.size()){
        for (int tmp : printer) 
        cout << tmp << ' ';
    }
    cout << '\n';
    printer.clear(); 
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            edge[i][j] = INF;
            if (i == j) {
                edge[i][j] = 0;
                pi[i][j] = j;
            }
        }
    }
    for (int i=1; i<=m; i++){
        cin >> a >> b >> c;
        if (edge[a][b] > c){
            edge[a][b] = c;
            pi[a][b] = a;
        }
    }

    for (int s=1; s<=n; s++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (i == s || j == s) continue;
                if (edge[i][s] == INF || edge[s][j] == INF) continue;
                if (edge[i][j] > edge[i][s] + edge[s][j]){
                    edge[i][j] = edge[i][s] + edge[s][j];
                    pi[i][j] = pi[s][j];
                }
            }
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            edge[i][j] == INF? cout << 0 : cout << edge[i][j];
            cout << ' ';
        }
        cout << '\n';
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            find_path(i, j);
            print_path(i, j);
        }
    }
}