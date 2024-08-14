#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> counts(10, 0);
    while (n){
        counts[n % 10]++;
        n /= 10;
    }
    long long w = 1;
    for (int i = 0; i < 10; ++i){
        if (!counts[i]) continue;
        while (counts[i]--){
            answer += (w * i);
            w *= 10;
        }
    }
    return answer;
}