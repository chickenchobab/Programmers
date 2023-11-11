#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;
int r, c, t;
int map[51][51], reserved[51][51];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void show(){
    cout<<"\nthis is map\n";
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            printf("%3d", map[i][j]);
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void show_reserved(){
    cout<<"\nthis is reserved\n";
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            printf("%3d", reserved[i][j]);
        }
        cout<<'\n';
    }
    cout<<'\n';
}

bool is_valid(int ni, int nj){
    if(map[ni][nj]==-1) return false;
    if(ni<1 || ni>r || nj<1 || nj>c) return false;
    return true;
}

void contamiate(int i, int j){
    int cnt = 0;

    for(int d=0; d<4; d++){
        int ni = i+di[d];
        int nj = j+dj[d];
        if(!is_valid(ni,nj)) continue;
        
        reserved[ni][nj] += (map[i][j]/5);
        cnt++;
    }
    
    map[i][j] -= (map[i][j]/5)*cnt;
}

void clean(int num, int pos){

    int i = pos, j = 2;
    stack<ii> st;
    st.push({0,0});

    if(num == 1){
        for(; j < c; ++j) st.push({i, j});
        for(; i > 1; --i) st.push({i, j});
        for(; j > 1; --j) st.push({i, j});
        for(; i < pos; ++i) st.push({i, j});
    }
    else{
        for(; j < c; ++j) st.push({i, j});
        for(; i < r; ++i) st.push({i, j});
        for(; j > 1; --j) st.push({i, j});
        for(; i > pos; --i) st.push({i, j});
    }

    while(st.size()!=1){
        ii tmp = st.top();
        st.pop();
        int ni=tmp.first;
        int nj=tmp.second;
        int i = st.top().first;
        int j = st.top().second;
        map[ni][nj] = map[i][j];
    }
}

int main(){
    cin >> r >> c >> t;

    map[0][0] = 0;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> map[i][j];
            reserved[i][j]=0;
        }
    }

    while(t--){
        
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                if(map[i][j]>0) contamiate(i,j);
            }
        }

        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                map[i][j] += reserved[i][j];
                reserved[i][j]=0;
            }
        }

        //show();

        int num = 1;

        for(int i=1; i<=r; i++){
            if(map[i][1]<0){
                clean(num, i);
                num++;
            }
        }

        //show();
    }

    int ans = 0;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(map[i][j]==-1) continue;
            ans += map[i][j];
        }
    }

    cout<<ans;
    
}