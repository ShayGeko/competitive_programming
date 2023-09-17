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

vvi rev_a;

vll c;
void get(int v, int loop_parent=-1) {
    for(auto from : rev_a[v]) {
        if(from == loop_parent) continue;
        get(from);
        c[v] += c[from];
    }
};
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(auto &x : a) {
        cin >> x;
        --x;
    }
    rev_a.clear();
    c.clear();
    c.resize(n);
    for(auto &x : c) cin >> x;

    rev_a.resize(n);
    rep(i, 0, n) rev_a[a[i]].push_back(i);

    vi loop;
    vb vis(n, false);


    rep(i, 0, n) {
        if(!vis[i]) {
            stack<int> st;
            unordered_set<int> seen;
            st.push(i);

            while(!st.empty()) {
                auto v = st.top();st.pop();
                vis[v] = true;
                seen.insert(v);

                if(seen.find(a[v]) != seen.end()){
                    loop.push_back(v);
                } else {
                    st.push(a[v]);
                }
            }
        }
    }

    vector<int> ans;
    vb isInLoop(n, false);


    ans.reserve(n);

    vi deg(n);

    queue<int> q;
    rep(i, 0, n) if((deg[i] = rev_a[i].size()) == 0) q.push(i);

    while(!q.empty()) {
        int v = q.front(); q.pop();
        ans.push_back(v);

        if(!--deg[a[v]]) q.push(a[v]);
    }

    rep(i, 0, sz(loop)) {
        int start, cur;
        start = cur = a[loop[i]];
        int mini = cur;
        do {
            cur = a[cur];
            if(c[cur] < c[mini]) mini = cur;
        } while(cur != start);

        loop[i]=mini;

        start = cur = a[mini];

        do {
            ans.push_back(cur);
            cur = a[cur];
        } while(cur != start);
    }

    for(auto x : ans) cout << x + 1 << " ";
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