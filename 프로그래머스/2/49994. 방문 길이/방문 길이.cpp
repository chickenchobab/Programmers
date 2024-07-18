#include <string>
#include <unordered_map>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    bool visited[11][11][2] = {0,}; // 0:right, 1:down
    int i = 5, j = 5;
    unordered_map<char, int> dir = {{'L', 0}, {'R', 1}, {'U', 2}, {'D', 3}};
    int di[] = {0, 0, -1, 1}, dj[] = {-1, 1, 0, 0};
    
    for (const char &ch : dirs){
        int ni = i + di[dir[ch]];
        int nj = j + dj[dir[ch]];
        if (ni < 0 || ni > 10 || nj < 0 || nj > 10) continue;
        // i = ni, j = nj;
        switch (dir[ch]){
            case 0: 
                if(!visited[ni][nj][0]){
                    visited[ni][nj][0] = 1;
                    answer++;
                }
                break;
            case 1:
                if(!visited[i][j][0]){
                    visited[i][j][0] = 1;
                    answer++;
                }
                break;
            case 2:
                if (!visited[ni][nj][1]){
                    visited[ni][nj][1] = 1;
                    answer++;
                }
                break;
            case 3:
                if (!visited[i][j][1]){
                    visited[i][j][1] = 1;
                    answer++;
                }
        }
        i = ni, j = nj;
    }
    
    
    
    
    return answer;
}