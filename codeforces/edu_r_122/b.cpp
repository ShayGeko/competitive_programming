#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cnt1 = 0;
        for(auto c : s){
            if(c == '1') ++cnt1;
        }
        int ans;
        if(cnt1 == s.length() - cnt1) ans = cnt1 - 1;
        else ans = min(cnt1, (int) s.length() - cnt1);
        cout << ans << '\n';
    }
    return 0;
}