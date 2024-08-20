#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int n = board.size(), m = board[0].size();

    for (int i = 1; i < n; ++i){
        for (int j = 1; j < m; ++j){
            if(!board[i][j]) continue;
            board[i][j] += min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1]));
            answer = max(board[i][j], answer);
        }
    }

    return answer * answer;
}