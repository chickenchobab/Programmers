#include <string>
#include <vector>
#include <stack>

using namespace std;

int stringToNum(string str){
    int ret = 0, digit = 1;
    for (int i = str.length() - 1; i >= 0; --i){
        ret += (str[i] - '0') * digit;
        digit *= 10;
    }
    return ret;
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    stack<int> deleted;
    vector<int> up(n + 1), down(n + 1);
    
    for (int i = 0; i < n; ++i){
        answer += 'O';
        up[i] = i - 1;
        down[i] = i + 1;
    }
    
    int x;
    for (int c = 0; c < cmd.size(); ++c){
        switch (cmd[c][0]){
            case 'U':
                x = stringToNum(cmd[c].substr(2, cmd[c].length() - 2));
                while (x--) k = up[k];
                break;
            case 'D':
                x = stringToNum(cmd[c].substr(2, cmd[c].length() - 2));
                while (x--) k = down[k];
                break;
            case 'C':
                if (up[k] >= 0)
                    down[up[k]] = down[k];
                if (down[k] < n)
                    up[down[k]] = up[k];
                deleted.push(k);
                down[k] < n ? k = down[k] : k = up[k];
                break;
            case 'Z':
                if (deleted.empty()) break;
                int d = deleted.top();
                deleted.pop();
                if (up[d] >= 0)  down[up[d]] = d;
                if (down[d] < n) up[down[d]] = d;
                break;
        }
    }
    
    while (deleted.size()){
        int d = deleted.top();
        answer[d] = 'X';
        deleted.pop();
    }
    
    return answer;
}