#include <string>
#include <vector>

using namespace std;
int answer;
int N;
vector<int> edges[101];
int children[101];

int cntChildren(int cur, int prv){
    int ret = 0;
    for (int nxt : edges[cur]){
        if (nxt == prv) continue;
        ret += cntChildren(nxt, cur);
    }
    return children[cur] = ret + 1;
}

void findOptimalBridge(){
    answer = N;
    for (int i = 1; i <= N; ++i){
        answer = min(answer, abs(N - children[i] - children[i]));
    }
}

int solution(int n, vector<vector<int>> wires) {
    N = n;
    for (auto &w : wires){
        edges[w[0]].push_back(w[1]);
        edges[w[1]].push_back(w[0]);
    }
    cntChildren(1, 0); // root is 1 from now on.
    findOptimalBridge();
    return answer;
}