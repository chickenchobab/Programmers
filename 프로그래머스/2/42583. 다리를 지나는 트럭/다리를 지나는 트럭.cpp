#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int totalWeight = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < truck_weights.size(); ++i){
        
        while (weight - totalWeight < truck_weights[i]){
            answer++;
            if (answer - q.front().second >= bridge_length){
                totalWeight -= truck_weights[q.front().first];
                q.pop();
            }
        }
        totalWeight += truck_weights[i];
        q.push({i, answer});
    }
    
    while (q.size()){
        answer++;
        if (answer - q.front().second >= bridge_length) q.pop();
    }
    
    return answer + 1;
}