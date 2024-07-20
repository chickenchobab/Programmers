#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    
    for (int j = 0; j < moves.size(); ++j){
        for (int i = 0; i < board.size(); ++i){
            if (!board[i][moves[j] - 1]) continue;
            
            if (st.size() && st.top() == board[i][moves[j] - 1]){
                st.pop();
                answer += 2;
            }
            else {
                st.push(board[i][moves[j] - 1]);
            }
            board[i][moves[j] - 1] = 0;
            break;
        }
    }
    return answer;
}