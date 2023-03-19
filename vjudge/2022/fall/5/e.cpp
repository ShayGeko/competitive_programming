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
    string s;
    string t;
    cin >> s >> t;

    pii a = {0,0}, b = {0,0};

    for(auto c : s){
        if(c == '0'){
            a.first++;
        }
        else a.second++;
    }

    for(auto c : t){
        if(c == '0'){
            b.first++;
        }
        else b.second++;
    }

    if(b.first > a.first || b.second > a.second) {
        cout << s << '\n';
    }

    int mini = min(a.first / b.first, b.second / a.second);

    string ans = "";

    for(int i = 0; i < mini; ++i) {
        ans += t;
        a.first -= b.first;
        a.second -= b.second;
    }
    while(a.first--) ans+='0';
    while(b.first--) ans+='1';

    cout << ans << '\n';
    


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