#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for (int i = 0; i < arr.size(); ++i){
        while (answer.size() && answer.back() == arr[i]){
            answer.pop_back();
        }
        answer.push_back(arr[i]);
    }
    

    return answer;
}