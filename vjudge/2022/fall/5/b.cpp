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
    string t;
    cin >> t;

    string t_modi = "";
    for(auto c : t){
        if(c != 'a') t_modi+=c;
    }

    bool works = true;
    works ^= t_modi.length() % 2;

    works &= t_modi.substr(0, t_modi.length()/2) == t_modi.substr(t_modi.length()/2, t_modi.length()/2);
    
    
    string tt = t.substr(t.length() - t_modi.length()/2);
    if(tt.find('a') != string::npos) works = false;

    if(works){
        cout << t.substr(0, t.length() - t_modi.length()/2) << '\n';
    }
    else cout << ":(\n";
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