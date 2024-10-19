#include <iostream>
#include <algorithm>
#include <vector>
#include<set>
#include <map>


using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> vec(n);

    for(int i = 0; i < n; ++i) cin >> vec[i];


    map<string, int> word_cnt;
    for(auto x : vec) ++ word_cnt[x];

    for(auto [word, cnt] : word_cnt) {
        if(cnt > 1) {
            cout << word << '\n';
        }
    }
    

    return 0;
}