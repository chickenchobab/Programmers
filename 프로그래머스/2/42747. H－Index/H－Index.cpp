#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int i;
    for (i = 0; i < citations.size() && citations[i] >= i + 1; ++i);
    return min(i, (int)citations.size());
}