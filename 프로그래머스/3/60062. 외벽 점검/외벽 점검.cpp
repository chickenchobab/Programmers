#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size() + 1;
    
    int siz = weak.size();
    for (int i = 0; i < siz; ++i){
        weak.push_back(weak[i] + n);
    }
    
    do {  
        for (int start = 0; start < siz; ++start){
            int friendCnt = 1;
            int pos = weak[start] + dist[0];
            
            for (int nxt = start; nxt < start + siz; ++nxt){
                if (pos < weak[nxt]) {
                    ++friendCnt;
                    if (friendCnt > dist.size()) break;
                    pos = weak[nxt] + dist[friendCnt - 1];
                }
            }
            answer = min(answer, friendCnt);
        }
    }while (next_permutation(dist.begin(), dist.end()));
    
    return answer == dist.size() + 1 ? -1 : answer;
}