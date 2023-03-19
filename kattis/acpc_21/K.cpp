#include <bits/stdc++.h>

using namespace std;

const int maxn = 1001;
int freq[maxn];

const int mod = 1e6;
int dp[maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, k;
    cin >> n >> k;
    int a;
    for(int i = 0; i < n; ++i){
        cin >> a;
        ++freq[a];
    }
    int min = freq[1];
    for(int i = 2; i <= k; ++i){
        if(freq[i] < min) min = freq[i];
    }
    vector<int> ans;
    for(int i = 1; i <= k; ++i){
        if(freq[i] == min) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(auto t: ans){
        cout << t << " ";
    }

    return 0;
}