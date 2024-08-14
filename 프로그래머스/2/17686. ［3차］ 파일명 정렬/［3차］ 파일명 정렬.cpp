#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> head(files.size());
    vector<int> number(files.size());
    unordered_map<string, int> index;
    
    for (auto &f : files){
        index.insert({f, index.size()});
    }
    
    string tmp = "";
    int i, j;
    for (i = 0; i < files.size(); ++i){
        
        for (j = 0; j < files[i].size() && !isdigit(files[i][j]); ++j){
            if (isalpha(files[i][j])) tmp += tolower(files[i][j]);
            else tmp += files[i][j];
        }
        
        head[i] = tmp;
        tmp.clear();
        
        for (; j < files[i].size() && isdigit(files[i][j]); ++j)
            tmp += files[i][j];
        
        number[i] = stoi(tmp);
        tmp.clear();
    }
    
    stable_sort(files.begin(), files.end(), [head, number, index](string a, string b){
        int x = index.at(a), y = index.at(b);
        if (head[x] == head[y]) return number[x] < number[y];
        return head[x] < head[y];
    });
    return files;
}