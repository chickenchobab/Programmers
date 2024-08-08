#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer;
int N;

int getDistance(vector<int> & weak, int i, int j){
    i %= weak.size();
    j %= weak.size();
    if (weak[i] < weak[j]) return weak[j] - weak[i];
    return weak[j] + N - weak[i];
}

void checkWeakPoint(vector<int> &weak, vector<int> &dist, int start, int friendCnt, int weakCnt){
    // cout << "pos: "<< cur << ' ' << "friend : " << friendCnt << ' ' << "done :" << weakCnt << endl;
    if (weakCnt == weak.size()){
        answer = min(answer, friendCnt);
        return;
    }
    if (friendCnt > dist.size())
        return;
    
    int end;
    int fin = start + (weak.size() - weakCnt);
    for (end = start; end < fin; ++end){
        if (dist[friendCnt - 1] < getDistance(weak, start, end + 1)) break;
    }
    
    weakCnt += (end - start);
    
    if (weakCnt == weak.size()) 
        checkWeakPoint(weak, dist, end, friendCnt, weakCnt);
    else 
        checkWeakPoint(weak, dist, end + 1, friendCnt + 1, weakCnt + 1);
}

int solution(int n, vector<int> weak, vector<int> dist) {
    answer = dist.size() + 1;
    N = n;
    
    do {
        for (int i = 0; i < weak.size(); ++i)
            checkWeakPoint(weak, dist, i, 1, 1);
    }while (next_permutation(dist.begin(), dist.end()));
    
    
    if (answer == dist.size() + 1) return -1;
    return answer;
}