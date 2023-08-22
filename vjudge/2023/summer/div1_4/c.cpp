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
    int n;
    cin >> n;
    vvi a(n, vi(n));

    rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
    
    int maskBound = 1 << n;
    int maxMask = maskBound-1;
    vll groupSum(maskBound, 0);

    rep(mask, 0, maskBound) {
        rep(i, 0, n) {
            if(mask & (1<<i)) {
                rep(j, i+1, n) {
                    if(mask & (1<<j)) {
                        // yes it's slow but oh well
                        groupSum[mask] += a[i][j];
                    }
                }
            }
        }
    }

    ll MIN = -1e10;
    vll dp(maskBound, MIN);
    dp[0]=0;
    for(int mask = 0; mask < maxMask; ++mask) {
        int invMask = (~mask) & maxMask;
        int curMask = invMask;

        do {
            dp[mask|curMask]=max(dp[mask|curMask], dp[mask]+groupSum[curMask]);

            curMask = (curMask-1) & invMask;
        } while(curMask);
    }

    cout << dp[maxMask] << '\n';
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