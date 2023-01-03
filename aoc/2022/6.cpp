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

int m[26] = {0};
void solve(){
    string s;

    cin >> s;


    for(int i = 0; i <= 13; ++i) m[s[i]-'a']++;
    cout << s.size() << '\n';

    bool un = true;

    for(int j = 0; j <= 13; ++j){
        cout << m[s[j]] << " ";
        un &= m[s[j]-'a'] == 1;
    }
    cout << '\n';
    if(un){
        cout << 14  << '\n';
        return;
    }

    for(int i = 14; i < s.size(); ++i){
        //cout << i << '\n';
        m[s[i-14]-'a']--;
        m[s[i]-'a']++;
        bool un = true;

        for(int j = i - 13; j <= i; ++j){
            cout << m[s[j]-'a'] << " ";
            un = un && (m[s[j]-'a'] == 1);
        }
        cout << '\n';

        if(un){
            cout << i + 1  << '\n';
            return;
        }
    }

    cout << "done\n";
}
int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    //cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    return 0;
}