#include <string>
#include <vector>
#include <map>
using namespace std;

int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

bool isValidStep(vector<vector<int>> &board, int r, int c){
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return false;
    return board[r][c];
}

int makeBestMove(vector<vector<int>> &board, int curR, int curC, int opR, int opC){
    
    if (board[curR][curC] == 0) return 0;
    
    int bestSteps = 0;
    
    for (int d = 0; d < 4; ++d){
        int newR = curR + dr[d];
        int newC = curC + dc[d];
        if (!isValidStep(board, newR, newC)) continue;
        
        board[curR][curC] = 0;
        int steps = makeBestMove(board, opR, opC, newR, newC) + 1;
        board[curR][curC] = 1;
        
        // if can win then win
        if (bestSteps % 2 == 0 && steps % 2 == 1)
            bestSteps = steps;
        // delay losing
        else if (bestSteps % 2 == 0 && steps % 2 == 0)
            bestSteps = max(bestSteps, steps);
        // hasten winning
        else if (bestSteps % 2 == 1 && steps % 2 == 1)
            bestSteps = min(bestSteps, steps);
    }
        
    return bestSteps;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    return makeBestMove(board, aloc[0], aloc[1], bloc[0], bloc[1]);
}