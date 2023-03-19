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

vvi adj;
vi height;
vpii euler_path;
int p_ind;

void dfs(int v){
    euler_path.push_back({height[v], v});
    //euler_path[p_ind++] = {height[v], v};
    for(auto to : adj[v]){
        height[to] = height[v] + 1;

        dfs(to);
        euler_path.push_back({height[v], v});
    }
    if(sz(adj[v]) == 0) euler_path.push_back({height[v], v});
}

vb used;
void dfs1(int v){
    used[v] = true;

    for(auto to : adj[v]){
        dfs1(to);
    }
}

// codebook
struct Tree {
    typedef pii T;
	static constexpr T unit = {INT_MAX, INT_MAX};
	T f(T &a, T &b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T &val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

// also codebook
template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

void solve(){
    int n;
    scanf("%d", &n);
    // cin >> n;
    adj = vvi(n);

    fora(i, n){
        int m; 
        scanf("%d", &m);
        // cin >> m;
        fora(j, m){
            int b;
            scanf("%d", &b);
            // cin >> b;

            adj[i].pb(b-1);
        }
    }

    int q;
    // cin >> q;
    scanf("%d", &q);

    vpii queries(q);
    fora(i, q){
        int a, b;
        scanf("%d%d", &a, &b);
        // cin >> a >> b;
        queries[i] = {a-1,b-1};
    }

    height = vi(n);
    euler_path.clear();
    
    // find root
    used = vb(n, false);
    int root = 0;
    fora(i, n){
        if(!used[i]){
            dfs1(i);
            root = i;
        }
    }
    height[root] = 0;
    dfs(root);

    vi first_occurence(n, -1);
    fora(i,sz(euler_path)){
        auto node = euler_path[i];
        if(first_occurence[node.second] == -1){
            first_occurence[node.second] = i;
        }
    }

    // Tree rmq(p_ind, {INT_MAX, INT_MAX});
    // fora(i, p_ind){
    //     rmq.update(i, euler_path[i]);
    // }

    RMQ<pii> rmq(euler_path);

    for(auto qr : queries){
        if(qr.first == qr.second) {
            printf("%d\n", qr.first+1);
            // cout << a << '\n';
            continue;
            }
        int l = first_occurence[qr.first], r = first_occurence[qr.second];
        if(l > r) swap(l, r);
        
        printf("%d\n", rmq.query(l, r+1).second + 1 );
        // cout << rmq.query(l, r+1).second + 1 << '\n';
    }
}

int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    scanf("%d", &t);
    euler_path.reserve(20000);
    fora(i, t) {
        // cout << "Case " << i+1 << ":\n";
        printf("Case %d:\n",  i+1);
        solve();
    }
    // cout.flush();
    
    return 0;
}