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

string encrypt(string s){
    vi v;

    for(auto c : s) v.push_back(c == ' '? 0 : c - 'a' + 1);

    vi u(v.size());
    u[0] = v[0];
    for(int i = 1; i < u.size(); ++i){
        u[i] = v[i] + u[i-1];
    }
    string enc = "";
    for(auto c : u){
        enc += (c %= 27) == 0? ' ': 'a' + c - 1; 
    }

    return enc;
}
string decrypt(string s){
    string dec = "";

    vi u, v(s.size());

    for(auto c : s){
        u.push_back(c == ' '? 0: c - 'a' + 1); 
    }

    v[0] = u[0];
    int sum = v[0];
    for(int i = 1; i < u.size(); ++i){
        v[i] = (27 + u[i] - (sum%27)) % 27;
        sum+=v[i];
    }

    for(auto c : v){
        dec += (c %= 27) == 0? ' ': 'a' + c - 1; 
    }

    return dec;
}
void solve(){
    string s;
    char c;
    cin >> c;
    getline(cin, s);
    s=s.substr(1);
    if(c == 'e') cout << encrypt(s) << '\n';
    else cout << decrypt(s) << '\n';
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