#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size() / 2;
    unordered_set<int> visited;
    
    for (int i = 0; i < nums.size() && visited.size() < n; ++i){
        visited.insert(nums[i]);
    }
    
    return visited.size();
}