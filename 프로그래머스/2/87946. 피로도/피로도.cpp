#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<bool> visited;

void exploreDungeon(vector<vector<int>> &dungeons, int cur, int energy, int cnt){   
    answer = max(answer, cnt);
    energy -= dungeons[cur][1];
    
    for (int nxt = 0; nxt < dungeons.size(); ++nxt){
        if (visited[nxt]) continue;
        if (energy < dungeons[nxt][0]) continue;
        visited[nxt] = 1;
        exploreDungeon(dungeons, nxt, energy, cnt + 1);
        visited[nxt] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    visited.assign(dungeons.size(), 0);
    for (int start = 0; start < dungeons.size(); ++start){
        if (k < dungeons[start][0]) continue;
        visited[start] = 1;
        exploreDungeon(dungeons, start, k, 1);
        visited[start] = 0;
    }
    return answer;
}