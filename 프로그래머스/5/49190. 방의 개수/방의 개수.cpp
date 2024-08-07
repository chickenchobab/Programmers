#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <iostream>
using namespace std;

int answer;
int di[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dj[] = {0, 1, 1, 1, 0, -1, -1, -1};
typedef pair<int, int> p;
map<p, bool> nodeVisited;
map<pair<p, p>, bool> edgeVisited;

int solution(vector<int> arrows) {
    int answer = 0;
    int i = 0, j = 0;
    nodeVisited[{0, 0}] = 1;
    
    for (int &d : arrows){
        int mul = 2;
        while (mul--){
            int ni = i + di[d];
            int nj = j + dj[d];
            if (nodeVisited[{ni, nj}] && !edgeVisited[{{i, j}, {ni, nj}}]) {
            ++answer;
            }
            nodeVisited[{ni, nj}] = 1;
            edgeVisited[{{i, j}, {ni, nj}}] = edgeVisited[{{ni, nj}, {i, j}}] = 1;
            i = ni;
            j = nj;
        }
        
    }
    
    return answer;
}