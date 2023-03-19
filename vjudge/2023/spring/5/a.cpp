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


vi pi(vi &s){
    vi pr(sz(s));
    pr[0] = 0;
    for(int i = 1; i < sz(s); ++i){
        int j = pr[i-1];
        while(j > 0 && s[j] != s[i]) j = pr[j-1];
        if(s[j] == s[i]) ++j;
        pr[i] = j;
    }
    return pr;
}
void solve(){
    int n, m;
    cin >> n >> m;

    vi a(n), b(m);

    
    fora(i, n) cin >> a[i];
    fora(i, m) cin >> b[i];

    if(m == 1){
        cout << n << '\n';
        return;
    }
    for(int i = n - 1; i >= 1; i--)a[i] -= a[i-1];
    a[0] = 0;

    for(int i = m - 1; i >= 1; i--) b[i] -= b[i-1];
    b[0] = 0;

    vi str(n + m - 1);
    rep(i, 1, m) str[i-1] = b[i];
    str[m-1] = INT_MAX;
    rep(i, 1, n) str[m + i-1] = a[i];

    auto pr = pi(str);

    int cnt = 0;
    forc(c, pr){
        if(c == m-1) cnt ++;
    }
    cout << cnt << '\n';
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