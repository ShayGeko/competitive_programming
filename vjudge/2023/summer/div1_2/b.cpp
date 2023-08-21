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

vb visited, isPartOfLoop;
vi nextHop, loop, loopParent, ans;
vvi parents;
void findLoop(int v) {
    visited[v] = true;

    // loop
    if(visited[nextHop[v]]) {
        int start = v;
        int cur = v;

        do {
            isPartOfLoop[cur]=true;
            loop.push_back(cur);
            loopParent[nextHop[cur]] = cur;
            cur = nextHop[cur];
        } while(cur != start);
    } else {
        findLoop(nextHop[v]);
    }

}

vector<priority_queue<pair<int,int>>*> reachable;

void mergeQueues(priority_queue<pii> *a, priority_queue<pii> *b, int shift = 0) {
    while(!b->empty()) {
        auto x = b->top(); b->pop();

        a->push({x.first+shift, x.second});
    }
}


// cur node, init value shift, k, cutoff if loopSize < k
void getForBranch(int v, int shift, int k) {
    if(ans[v] && !isPartOfLoop[v]) return;
    
    reachable[v] = new priority_queue<pii>();
    reachable[v]->push({shift, v});
    for(auto prev : parents[v]) {
        if(prev != loopParent[v]) {
            getForBranch(prev, shift+1, k);
            if(reachable[v]->size() < reachable[prev]->size()) {
                swap(reachable[prev], reachable[v]);
            }
            mergeQueues(reachable[v], reachable[prev]);
        }
    }

    while(reachable[v]->size() && reachable[v]->top().first - shift > k) {
        reachable[v]->pop();
    }
    ans[v]=reachable[v]->size();
} 
void solve(){
    int n, k;
    cin >> n >> k;

    nextHop = vi(n);
    for(auto &x : nextHop) {
        cin >> x; --x;
    }

    visited = vb(n, false);
    isPartOfLoop = vb(n, false);
    
    parents = vvi(n);
    rep(i, 0, n) {
        parents[nextHop[i]].push_back(i);
    }
    

    int shift = 0;
    reachable = vector<priority_queue<pii>*>(n);
    ans = vi(n, 0);
    

    loopParent = vi(n, -1);
    rep(i, 0, n) {
        // new component
        if(!ans[i]) {
            loop.clear();
            findLoop(i);
            shift = 0;

            // get answers for branches (non-loop)
            for(auto v: loop) {
                getForBranch(v, shift, k);
                // shift is a starting point
                // in max priority queue if node X is (0, X), node X+1 (child) is (-1, X+1)
                shift--;
            }
            shift = 0;
            int loopSizeCap = sz(loop) - 1;

            priority_queue<pii> loopReachable;
            int cur = loop[0];

            do {
                while(loopReachable.size() && loopReachable.top().first - shift > k) {
                    loopReachable.pop();
                }

                ans[cur] += loopReachable.size();

                while(reachable[cur]->size()) {
                    auto x = reachable[cur]->top();
                    reachable[cur]->pop();
                    loopReachable.push({
                        shift + max(x.first-shift, k-loopSizeCap),
                        x.second
                    });
                }
                cur = nextHop[cur];
                shift--;
            }
            while(loopReachable.size());
        }
    }

    rep(i, 0, n) {
        cout << ans[i] << '\n';
    }

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