#include <bits/stdc++.h>
using namespace std;
class PlayingCubes{
public:
    vector<int> composeWords(vector<string> &cubes, vector<string> &words){
        for(auto & cube : cubes){
            sort(cube.begin(), cube.end());
        }
        for(auto & word : words){
            sort(word.begin(), word.end());
        }
        vector<int> ansv;
        for(int i = 0; i < words.size(); ++i){
            buildGraph(words[i], cubes);

            int maxflow = 0;

            int f;
            memset(used, 0, sizeof used);
            while((f = flow(0, 19, INF)) > 0){
                maxflow += f;
                memset(used, 0, sizeof used);
            }
            if(maxflow == words[i].size()){
                ansv.push_back(i);
            }
        }

        return ansv;
    }
private:
    const int INF = 1e9;
    int capacity[20][20];
    vector<int> adj[20];
    bool used[20];
    int flow(int cur, int t, int bottleneck){
        if(cur == t) return bottleneck;
        used[cur] = true;
        for(auto to : adj[cur]){
            if(used[to] || capacity[cur][to] <= 0) continue;
            int f = flow(to, t, min(capacity[cur][to], bottleneck));

            if(f > 0) {
                capacity[cur][to] -= f;
                capacity[to][cur] += f;

                return f;
            }
        }
        return 0;
    }
    void buildGraph(const string& word, const vector<string>& cubes){
        memset(capacity, 0, sizeof capacity);
        for(auto & v : adj){
            v.clear();
        }
        // source
        for(int i = 1; i <= word.length(); ++i){
            capacity[0][i] = 1;
            adj[0].push_back(i), adj[i].push_back(0);
        }
        for(int i = 11; i <= 10 + cubes.size(); ++i){
            capacity[i][20 - 1] = 1;
            adj[i].push_back(20 - 1), adj[20 - 1].push_back(i);
        }
        for(int j = 0; j < cubes.size(); ++j){
            for(int w = 0; w < word.length(); ++w){
                for(int c = 0; c < cubes[j].length(); ++c){
                    if(word[w] == cubes[j][c]){
                        capacity[w + 1][j + 11] = 1;
                        adj[w + 1].push_back(j + 11);
                        adj[j + 11].push_back(w + 1);
                    }
                }
            }
        }
    }
};

int main(){
    PlayingCubes* solver = new PlayingCubes();

    vector<string> cubes = {"ABCDEF", "DEFGHI", "OPQRST", "MNZLSA", "QEIOGH", "IARJGS"};
    vector <string> words = {"DOG", "CAT", "MOUSE", "BIRD", "CHICKEN", "PIG", "ANIMAL"}
    ;

    vector<int> ans = solver->composeWords(cubes, words);

    for(int an : ans){
        cout << an << " ";
    }
    cout << '\n';

    return 0;
}