#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<float> failRate;

bool compare(const int &a, const int &b){
    if (failRate[a] == failRate[b])
        return a < b;
    return failRate[a] > failRate[b];
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<float> sum(N + 2, 0);
    failRate.resize(N + 1, 0);
    
    for (const int &s : stages){
        sum[s] ++;
    }
    for (int i = N; i >= 1; --i){
        sum[i] += sum[i + 1];
    }
    for (int i = 1; i <= N; ++i){
        if (sum[i])
            failRate[i] = (sum[i] - sum[i + 1]) / sum[i];
        // cout << failRate[i] << ' ';
    }
    for (int i = 1; i <= N; ++i){
        answer.push_back(i);
    }
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}