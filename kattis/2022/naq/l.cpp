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
typedef unsigned long long ull;

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

ull gcd(ull a, ull b){
    if(a == 0) return b;
    if(b == 0) return a;

    return gcd(b, a % b);
}
ull getManh(ll t){
    ull manh = ((t+1)*(t+2)/2 - 2*t - 1)*4 + 4*t + 1;
    return manh;
}
void solve(){
    ll s, t;
    cin >> t >> s;

    ull manh,spidey;
    
    if(s < 2) spidey = 0;
    else {
        int diag_size = s + 1;
        int a =  diag_size % 3, n = (diag_size + 2) / 3;
        spidey = (ull) (n-1)  * (a + (diag_size-3))/ 2 + !a;
    }

    manh = getManh(t);
    spidey= 4 * spidey + getManh(s);

    ll gc = gcd(manh, spidey);

    manh /= gc;
    spidey /= gc;

    if(spidey == 1) cout << manh << '\n';
    else if(manh > spidey) cout << "1\n";
    else cout << manh << "/" << spidey << '\n';
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