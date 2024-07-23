#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer, songs;
    unordered_map<string, int> playsByGenre;
    
    for (int i = 0; i < genres.size(); ++i){
        songs.push_back(i);
    }
    
    for (int i = 0; i < genres.size(); ++i){
        playsByGenre[genres[i]] += plays[i];
    }
    
    sort(songs.begin(), songs.end(), [playsByGenre, genres, plays](int a, int b){
        if (playsByGenre.at(genres[a]) == playsByGenre.at(genres[b])){
            if (plays[a] == plays[b]) 
                return a < b;
            return plays[a] > plays[b];
        }
        return playsByGenre.at(genres[a]) > playsByGenre.at(genres[b]);
    });
    
    bool found = 0;
    string g = "";
    for (int s : songs){
        if (genres[s] != g) {
            found = 0;
            answer.push_back(s);
        }
        else {
            if (found) continue;
            else {
                found = 1;
                answer.push_back(s);
            }
        }
        g = genres[s];
    }
    return answer;
}