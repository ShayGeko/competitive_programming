#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;
void solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;

    int m;
    cin >> m;
    vector<string> friends(m);
    for(int i = 0; i < m; ++i){
        cin >> friends[i];
    }

    vi lpos[26];

    for(int i = 0; i < n; ++i){
        lpos[str[i] - 'a'].push_back(i);
    }

    for(int i = 0; i < m; ++i){
        vi lcount(26, 0);
        for(auto c : friends[i]) lcount[c -'a']++;

        int maxi = 0;
        for(int j = 0; j < 26; ++j){
            if(lcount[j]){
                maxi = max(maxi, lpos[j][lcount[j] - 1]);
                // cout << 'a' + j << " " << maxi << '\n';
            }
        }
        cout << maxi + 1 << '\n';
    }


}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}