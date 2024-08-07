#include <string>
#include <vector>

using namespace std;

int N;
int answer;
bool queenOnRow[12], queenOnCrossAdd[25], queenOnCrossSub[25];

void putQueenOnCol(int col){
    
    if (col == N) {
        ++answer;
        return;
    }
    
    for (int row = 0; row < N; ++row){
        if (queenOnRow[row] || queenOnCrossAdd[col + row] || queenOnCrossSub[col - row + N - 1]) continue;
        queenOnRow[row] = 1;
        queenOnCrossAdd[col + row] = 1;
        queenOnCrossSub[col - row + N - 1] = 1;
        putQueenOnCol(col + 1);
        queenOnRow[row] = 0;
        queenOnCrossAdd[col + row] = 0;
        queenOnCrossSub[col - row + N - 1] = 0;
    }
}

int solution(int n) {
    N = n;
    putQueenOnCol(0);
    return answer;
}