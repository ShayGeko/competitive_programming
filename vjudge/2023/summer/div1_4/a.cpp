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

bool hasOdd1Runs(int a) {
    int cnt = 0;

    while(a) {
        if(a&1) cnt++;
        else{
            if(cnt%2) return true;
            cnt = 0;
        }
        a>>=1;
    }

    return cnt%2;
}
void solve(){
    int n, m;
    cin >> n >> m;

    int maskBound=1<<n;
    vvi dp(m+1, vi(maskBound, 0));
    dp[0][0]=1;

    vvi transitions(maskBound);

    rep(mask, 0, maskBound) {
        int invMask = (~mask)&(maskBound-1);
        int nextMask = invMask;

        transitions[mask].push_back(nextMask);
        while(nextMask) {
                nextMask = (nextMask - 1) & invMask;
                // must fill up the whole column and shouldn't leave 1-cell gaps in the prev column
                if(!hasOdd1Runs(nextMask^invMask)) {
                    transitions[mask].push_back(nextMask);
                }
            }
    }

    
    rep(i, 1, m+1) {
        rep(mask, 0, maskBound) {
            for(auto nextMask : transitions[mask]) {
                dp[i][nextMask] = ((ll)dp[i][nextMask] + dp[i-1][mask]) %p;
            } 
        }
    }

    // number of ways to get to empty column m+1 with no "overflows"
    cout << dp[m][0] << '\n';
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