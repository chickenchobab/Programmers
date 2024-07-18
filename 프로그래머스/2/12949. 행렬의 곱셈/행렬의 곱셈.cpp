#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int l, m, n;
    
    l = arr1.size(); m = arr2.size(); n = arr2[0].size();
    
    answer.assign(l, vector<int>(n, 0));
    
    for (int i = 0; i < l; ++i){
        for (int j = 0; j < n; ++j){
            for (int k = 0; k < m; ++k){
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return answer;
}