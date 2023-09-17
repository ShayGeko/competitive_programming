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

const int inf = 1e9;

struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = 0, fullval = 0;
    bool mflipped=false;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    Node(vi& v, string s, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, s, lo, mid); r = new Node(v, s, mid, hi);
            val = l->val ^r->val;
            fullval = l->fullval ^ r-> fullval;
        }
        else {
            val = s[lo] == '1' ? v[lo] : 0;
            fullval = v[lo];
        }
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) ^ r->query(L, R);
    }
    void flip(int L, int R) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mflipped = !mflipped;
            val = fullval ^ val;
        } else {
            push(), l->flip(L, R), r->flip(L, R);
            val = l->val ^ r->val;
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if(mflipped)
            l->flip(lo, hi), r->flip(lo, hi), mflipped=false;
    }
};

void solve(){
    int n;
    cin >> n;

    vi nums(n);
    string s;

    for(auto &x : nums) cin >> x;
    cin >> s;

    Node node(nums, s, 0, n);

    int m;
    cin >> m;

    rep(i, 0, m){
        int t;
        cin >> t;
        if(t == 1) {
            int l, r;
            cin >> l >> r;
            node.flip(l-1, r);
        } else {
            int g;
            cin >> g;

            int a = node.query(0, n);
            if(!g) a ^= node.fullval;
            cout << a << ' ';
        }
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

     cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    
    return 0;
}