#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
#include <cstdio>

using namespace std;

typedef pair<float, float> point;
typedef tuple<float, float, float> edge;

int n; 
float x,y,sum;
point p[101];
vector<edge> e;
int set[101];

float distance(point a, point b){
    float dx=a.first-b.first;
    float dy=a.second-b.second;
    return sqrt(dx*dx+dy*dy);
}

int find(int x){
    if(set[x]<=0) return x;
    return (set[x]=find(set[x]));
}

void unite(int a,int b){
    int c1=find(a);
    int c2=find(b);
    if(set[c1]<set[c2])
        set[c2]=c1;
    else{
        if(set[c1]==set[c2])
            set[c2]--;
        set[c1]=c2;
    }

}

int main(){
    cin>>n;
    p[0]={0,0};
    for(int i=1; i<=n;i++){
        cin>>x>>y;
        p[i]={x,y};
        for(int j=1;j<=i;j++){
            e.push_back({distance(p[i], p[j]), j, i});
        }
    }

    sort(e.begin(), e.end());

    for(int i=0;i<e.size();i++){
        float d=get<0>(e[i]);
        float a=get<1>(e[i]);
        float b=get<2>(e[i]);
        
        if(find(a)==find(b)) continue;
        unite(a,b);
        sum+=d;

    }

    printf("%.2lf",sum);

}