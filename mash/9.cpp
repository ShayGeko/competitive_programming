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

istream &operator >> (istream& is, pii &p){
    is >> p.first >> p.second;
    return is;
}
ostream &operator << (ostream& os, pii &p){
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

int n, v1, v2;
vi a, b;
int getTime(int t){
    int cur = v1 + t;
    for(int i = 0; i < sz(a); ++i){
        if(cur % a[i] == 0){
            cur += b[i];
        }
        else{
            cur = cur + (a[i] - cur % a[i]) + b[i];
        }
    }

    return cur + v2;
}
int binary_search(int l, int r, int pivot){
    if(r < l) return -1;
    if(l == r) return l;
    if(l == r - 1){
        if(getTime(r) == pivot) return r;
        else return l;
    }

    int m = l + ((r-l) >> 1);

    if(getTime(m) > pivot) return binary_search(l, m, pivot);
    else return binary_search(m, r, pivot);
}
void solve(){
    cin >> n >> v1 >> v2;
    
    a.resize(n);b.resize(n);
    rep(i, 0, n) cin >> a[i] >> b[i];

    int t_0 = v1 + v2;

    int cur = v1;
    for(int i = 0; i < n; ++i){
        if(cur % a[i] == 0){
            cur += b[i];
        }
        else{
            cur = cur + (a[i] - cur % a[i]) + b[i];
        }
    }

    t_0 = getTime(0);

    
    cout << binary_search(0, t_0, t_0);

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