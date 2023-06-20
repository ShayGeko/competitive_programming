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

typedef struct node {
    int val;
    int subtree = 1;
    node *l = nullptr, *r = nullptr;
} node_t;

void insert(node_t* node, int v) {
    node->subtree++;
    if(v < node->val) {
        if(!node->l) {
            node->l = new node_t();
            node->l->val = v;
        }
        else insert(node->l, v);
    }
    else {
        if(!node->r) {
            node->r = new node_t();
            node->r->val = v;
        }
        else insert(node->r, v);
    }
}
ll dfs(node_t* v) {
    ll cur = 1;
    if(v->l && v->r) ++cur;

    if(v->l) cur*=dfs(v->l);
    if(v->r) cur*=dfs(v->r);

    

    return cur;
}
void solve(int n){
    node_t* root = new node_t();

    vi nums(n);
    rep(i, 0, n) cin >> nums[i];
    root->val = nums[0];
    rep(i, 1, n) insert(root, nums[i]);

    ll ans = dfs(root);
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    
    
    while(cin >> t && t > 0){
        solve(t);
    }
    cout.flush();
    
    return 0;
}