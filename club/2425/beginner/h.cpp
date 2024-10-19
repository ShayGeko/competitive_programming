#include <iostream>
#include <algorithm>
#include <vector>
#include<set>
#include <map>


using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);

    for(int i = 0; i < n; ++i) cin >> vec[i];


    map<int, int> word_cnt;
    for(auto x : vec) ++ word_cnt[x];
    
    int ans = 0;
    for(auto [num, cnt] : word_cnt) {
        if(cnt > num) ans += cnt - num;
        else if(cnt < num) ans += cnt;
    }
    cout << ans << '\n';

    return 0;
}