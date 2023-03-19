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

    int i = 1;
    while(i < s.length() && s[i] >= s[i-1]) ++i;

    bool decreased = false;
    
    for(; i < s.length(); ++i){
        if(decreased && s[i] < s[i-1]) s[i] = s[i-1];
        else if(s[i] > s[i-1]){
            decreased = true;
            s[i] = s[i-1];
        }
    }

    cout << s << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}