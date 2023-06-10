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
const ll p = 998244353;

vector<ll> fact;
vector<ll> revfact;
ll binpow(ll n, ll k){
    if(k == 0) return 1;
    if(k == 1) return n%p;
    
    ll a = binpow(n, k>>1);

    return  (((a * a) % p) * ((k&1)?n:1)) % p;
}
ll arrange(int n, int k){
    if(k>n) return 0;
    return (fact[n] * revfact[n-k])%p;
}
ll choose(int n, int k) {
    if(k>n)return 0;
    return (arrange(n,k)*revfact[k])%p;
}

// i goes from log2(m) to 0
// at every state, we assume that all previous bits of m are set
// meaning curNum pattern and m have the same prefix of length i
// otherwise, all configurations with mask's bits set are allowed
// bitsLeftIn Mask says how many bits are set on mask[i..rend]
ll countForMask(int i, int mask, int m, int bitsLeftInMask) {
    ll bit = 1ll<<i;
    // last bit
    if(i == 0) {
        // last bit of m is 0
        if(!(m & bit)){
            // if m[i] is not set and mask[i] is set
            // there is no way to satisfy the mask with the cur prefix
            if(mask & bit) return 0;
            // otherwise we satisfy the mask with setting last bit to 0
            else return 1;
        }
        // if last bit of mask is set, and last bit of m is set, only 1 satisfies
        if(mask & bit)
            return 1;
        // otherwise we can set both 0 or 1
        return 2;
    }

    if(mask & bit){
        // if mask[i] is set, but m[i] isn't, no way to satisfy mask with cur prefix
        if(!(m & bit)) return 0;
        // otherwise "set" prefix[i] to 1, and count further
        return countForMask(i-1, mask, m, bitsLeftInMask - 1);
    }
    // mask is not set, bit can be anything
        ll resultBounded = countForMask(i-1, mask, m, bitsLeftInMask);            
        // m[i] is not set, so can only set 0 to prefix[i]
        if(!(m & bit)) return resultBounded;

        // m[i] is set. Options:
        // a) Set prefix[i] to 1 and compute bounded
        // b) Set prefix[i] to 0 and compute unbounded

        
        // bitsLeftInMask bits have to be set, and other bits can be anything
        ll resultUnbounded = (1LL << (i-bitsLeftInMask));

    return (resultBounded + resultUnbounded) % p;
}

void solve(){
    int n, k, m;
    cin >> n >> k >> m;

    int fprecompsz = m+1;


    fact.resize(fprecompsz+1);
    revfact.resize(fprecompsz+1);

    fact[0] = 1;
    rep(i, 1, fprecompsz + 1) fact[i] = (fact[i-1]*i) % p;

    revfact[fprecompsz] = binpow(fact[fprecompsz], p - 2);
    for(int i = fprecompsz - 1; i >= 0; i--) revfact[i] = (revfact[i+1]*(i+1))%p;

    // rep(x, 0, m) cout << mC[x] << '\n';

    int highestBit = log2(m)+1;
    vector<ll> cntAnd(m+1);
    vector<ll> waysToGetXBitsSetInAnd(highestBit+1, 0);

    // cout << countForMask(highestBit, 8, m, 1);
    rep(i, 0, m+1){
        int maskBitsSet = __builtin_popcount(i);
        // set of IDs that satisfy the mask if all of them were ANDed
        cntAnd[i] =  countForMask(highestBit, i, m, maskBitsSet);
        

        // Compute the number of tuples in a multiset for
        // ways to get AND to have at least x bits
        waysToGetXBitsSetInAnd[maskBitsSet] =
         ((ll)waysToGetXBitsSetInAnd[maskBitsSet]+arrange(cntAnd[i], n))%p;
    }

    ll ans = 0;
    ll modif = -1;
    // inclusion-exclusion
    // waysToGetXBitsSetInAnd stores multiset sizes of ID tuples
    // that result in (at least) k bits set after ANDing all of them
    // But it overcounted for duplicate tuples:
    // (1111, 0111) satisfies masks [0110, 0011, 0101]
    // so it was included 3 times in this counting for k = 2
    // inclusion-exclusion like string patterns from cp-algo
    ll x = sz(waysToGetXBitsSetInAnd);
    rep(i, k, x){
        modif*=-1;
 
        ans = (ans + modif*((choose(i-1,i-k)*waysToGetXBitsSetInAnd[i]))%p+p)%p;
    }

    cout << ans << '\n';
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