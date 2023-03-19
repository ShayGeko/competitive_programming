#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define has(a, b) (a.find(b) != a.end())
#define imin(a, b) a = min(a, b)
#define imax(a, b) a = max(a, b)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define fora(i, n) for(int i = 0; i < n; i++)
#define forb(i, n) for(int i = 1; i <= n; i++)
#define forc(a, b) for(const auto &a : b)
#define ford(i, n) for(int i = n; i >= 0; i--)

typedef pair<int, int> pii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

template <class T>
istream &operator >> (istream& is, pair<T, T> &p){
    is >> p.first >> p.second;
    return is;
}
template <class T>
ostream &operator << (ostream& os, pair<T, T> &p){
    os << p.first << " " << p.second;
    return os;
}
template <class T>
pair<T, T> operator + (pair<T,T> &a, pair<T,T> &b){
    return {a.first + b.first, a.second + b.second};
}

template <class T>
pair<T, T> operator - (pair<T,T> &a, pair<T,T> &b){
    return {a.first - b.first, a.second - b.second};
}

template<class T>
vector<T> operator+(const vector<T> &a, const vector<T> &b){
    assert(sz(a) == sz(b));

    vector<T> res(a);
    fora(i, sz(b)){
        res[i] += b[i];
    }

    return res;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

void solve(){
    string s[2];
    cin >> s[0];

    s[1] = s[0];

    for(auto &c : s[1]){
        c = '0' + ('1'-c);
    }
    int ind = sz(s[1]) - 1;

    while(ind && s[1][ind] == '1'){
        s[1][ind]='0';
        ind--;
    }
    if(ind == -1){
        s[1].insert(s[1].begin(), '1');
        s[0].insert(s[0].begin(), '0');
    }
    else s[1][ind] = '1';

    // cout << s[0] << " " << s[1] << '\n';
    int a = 0, b = 0;
    fora(i, sz(s[1])){
        a+=s[0][i] == '1';
        b+=s[1][i] == '1';
    }

    vvi dp(sz(s[0]), vi(2, 0));
    int n = sz(s[0]);
    dp[n-1][0] = s[0][n-1] == '1';
    dp[n-1][1] = s[1][n-1] == '1';

    for(int i = sz(s[0]) - 2; i>= 0; i--){
        rep(j, 0, 2){
            if(s[j][i] == '0'){
                dp[i][j] = dp[i+1][j];
            }
            else {
                // choose between:
                // a: 2^(i) + best-suffix-starting-at-i+1
                // b: 2^(i+1) - best-suffix-inverse-starting-at-i+1
                dp[i][j] = 1 + min(dp[i+1][j], dp[i+1][1-j]);
            }
        }
    }

    cout << dp[0][0] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    
    return 0;
}