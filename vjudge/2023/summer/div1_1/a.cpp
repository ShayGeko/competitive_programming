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

vvi dp;
int get_edit_dist(string &a, string &b, int i, int j){
    if(i < 0) return j+1;
    if(j< 0) return i+1;
    if(dp[i][j] >= 0) return dp[i][j];

    if(i==0 && j==0) return dp[i][j] = a[i] != b[j];

    dp[i][j] = INF;

    // cases:
    // equals - cost: dp[i-1][j-1] - edit distance without this char
    // doesn't equal:
    // - change char to be the other - dp[i-1][j-1] + 1
    // - remove char - dp[i-1][j] + 1
    // - add char - dp[i][j-1] + 1

    if(i) dp[i][j] = min(dp[i][j], get_edit_dist(a, b, i-1, j)+1);
    if(j) dp[i][j] = min(dp[i][j], get_edit_dist(a, b, i, j-1)+1);
    
    int char_eq = a[i] == b[j];
    dp[i][j] = min(dp[i][j], get_edit_dist(a, b, i-1,j-1) + !char_eq); 

    return dp[i][j];
}
void solve(){
    string a, b;
    cin >> a >> b;
    int n = sz(a), m = sz(b);

    dp = vvi(n, vi(m, -1));

    int edit_dist = get_edit_dist(a, b, n-1, m-1);

    cout << edit_dist << '\n';
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