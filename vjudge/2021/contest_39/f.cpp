
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 2;

vector<int> stones;

bool dp[maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;

    int stone;
    for(int i = 0; i < n; ++i){
        cin >> stone;
        stones.push_back(stone);
    }

    for(auto st : stones){
        dp[st] = true;
    }
    bool winnable;
    for(int i = 1; i <= k; ++i){
        winnable = false;
        for(auto st : stones){
            if(i - st >= 0) winnable |= !(dp[i - st]);
        }
        dp[i] = winnable;
    }

    if(dp[k]) {
        cout << "First\n";
    }
    else cout << "Second\n";

    return 0;
}