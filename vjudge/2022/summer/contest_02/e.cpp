#include <bits/stdc++.h>

using namespace std;

vector<string> words;
set<string> combinations;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string word;
    while(cin >> word){
        words.push_back(word);
    }

    for(int i = 0; i < words.size(); ++i){
        for(int j = 0; j < words.size(); ++j){
            if(i == j) continue;
            combinations.insert(words[i] + words[j]);
        }
    }
    for(auto comb : combinations){
        cout << comb << '\n';
    }
    return 0;
}