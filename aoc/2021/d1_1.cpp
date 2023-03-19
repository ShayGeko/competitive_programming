#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}
ostream &operator << (ostream& os, pii &p){
    cout << p.first << " " << p.second;
    return os;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

void solve(){
    int n, p;
    cin >> n;
    p = n;
    int cnt = 0;

    vi c;
    c.push_back(n);
    cin >> n;
    c.push_back(n);
    cin>>n;
    c.push_back(n);
    while(cin >> n){
        c.push_back(n);

        if(c.back() > c[c.size() - 4]) ++cnt;
    }

    cout << cnt << '\n';
}

int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    return 0;
}