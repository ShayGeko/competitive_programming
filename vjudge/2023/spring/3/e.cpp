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
vector<bitset<251>> orange_shades_in_st;
vector<int> orange_shades;
int p_ind;

void dfs(int v, int p){
    euler_path.push_back({height[v], v});
    orange_shades_in_st[v].set(orange_shades[v], true);
    //euler_path[p_ind++] = {height[v], v};
    for(auto to : adj[v]){
        if(to == p) continue;
        height[to] = height[v] + 1;
        
        dfs(to, v);
        euler_path.push_back({height[v], v});
        orange_shades_in_st[v] |= orange_shades_in_st[to];
    }
    if(sz(adj[v]) == 0) euler_path.push_back({height[v], v});
}

// codebook
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
    int n, q, r;
    scanf("%d%d%d", &n, &q, &r);
    orange_shades.resize(n);
    orange_shades_in_st.resize(n);

    adj = vvi(n);
    fora(i, n){
        scanf("%d", &orange_shades[i]);
        // start from 0
        orange_shades[i]--;
    }
    int a, b;
    fora(i, n-1){
        scanf("%d %d", &a, &b);

        adj[a].pb(b);
        adj[b].pb(a);
    }   

    vpii queries(q);
    fora(i, q){
        int a, b;
        scanf("%d %d", &a, &b);
        queries[i] = {a,b};
    }

    height = vi(n);
    euler_path.clear();
    
    height[r] = 0;

    // compute the euler traveral, heights, and number of oranges in each node's subtree
    dfs(r, -1);

    vi first_occurence(n, -1);
    fora(i,sz(euler_path)){
        auto node = euler_path[i];
        if(first_occurence[node.second] == -1){
            first_occurence[node.second] = i;
        }
    }

    RMQ<pii> rmq(euler_path);

    for(auto qr : queries){
        int lca;
        if(qr.first == qr.second) {
            lca = qr.first;
        }
        else {
            int l = first_occurence[qr.first], r = first_occurence[qr.second];
            if(l > r) swap(l, r); 
            
            lca = rmq.query(l, r+1).second;
        }
        // number of set bits in the bitset
        int orange_cnt = orange_shades_in_st[lca].count();

        printf("%d\n", orange_cnt);
    }
}

int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    scanf("%d", &t);
    fora(i, t) {
        solve();
    }
    // cout.flush();
    
    return 0;
}



/*




ueries :
4 4
8 6
0 6
7 0
7 2
0 0
2 3


*/