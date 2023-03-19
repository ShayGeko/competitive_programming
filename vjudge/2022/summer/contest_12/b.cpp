#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;
void solve(){
    string s;
    cin >> s;

    vector<char> pos(26, 'z' + 1);
    pos[0] = s[0];
    for(int i = 1; i < s.length(); ++i){
        int j = 0;
        while(j < 26 && s[i] > pos[j]) ++j;
        pos[j] = s[i];
    }

    int i = 0;
    while(i < 26 && pos[i] <= 'z') ++i;

    cout << 26 - i << '\n';

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