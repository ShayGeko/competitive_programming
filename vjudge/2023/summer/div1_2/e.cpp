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

vi capacity;
vvi adj;

vi root;
vi tsize;
vi edge_cnt;
int find(int v) {
    if(root[v] == v) return v;

    return root[v] = find(root[v]);
}
void join(int a, int b) {
    int ra = find(a), rb = find(b);

    if(tsize[ra] < tsize[rb]) swap(ra, rb);

    root[rb] = ra;
    tsize[ra] += tsize[rb];
    edge_cnt[ra] += edge_cnt[rb] + 1;
    capacity[ra] += capacity[rb] - 2;

}

void remove_edge(int r) {
    edge_cnt[r]--;
    capacity[r]+=2;
}
int removableEdgesCnt(int r) {
    return edge_cnt[r] - tsize[r] + 1;
}
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    capacity = vi(n);
    rep(i, 0, n) cin >> capacity[i];

    adj = vvi(n);
    
    root = vi(n);
    rep(i, 0, n) root[i]=i;
    tsize = vi(n, 1);
    edge_cnt = vi(n, 0);

    rep(i,0,m) {
        int a, b; 
        cin >> a >> b;

        int root_a = find(a);
        int root_b = find(b);
        if(find(a) != find(b)) {
            join(root_a, root_b);
        } else {
            capacity[root_a] -=2;
            ++edge_cnt[root_a];
        }
    }

    vi roots;

    rep(i, 0, n) if (find(i) == i) roots.push_back(i);

    // for(auto r : roots) {
    //     cout << "Component " << r 
    //         << " | edges: "<< edge_cnt[r] << " node_cnt: " << tsize[r] 
    //         << " capacity: " << capacity[r] << " removable_edges: " << edge_cnt[r] - tsize[r] + 1 << '\n';
    // }

    auto comp = [](int a, int b) {
        if(capacity[a] == capacity[b]) {
            return removableEdgesCnt(a) < removableEdgesCnt(b);
        } else if(capacity[a] == 1 && removableEdgesCnt(a)==0) {
            return true;
        } else if(capacity[b] == 1 && removableEdgesCnt(b) == 0) {
            return false;
        }
        return capacity[a] < capacity[b];
    };
    priority_queue<int, vector<int>, decltype(comp)> pq(all(roots),comp);

    int actions = 0;

    while(pq.size() > 1) {
        int a = pq.top();pq.pop();
        int b = pq.top();pq.pop();


        if(capacity[a] && capacity[b]){
            join(a, b);
            ++actions;

            pq.push(find(a));
        } else {
            if(capacity[a] < capacity[b]) swap(a,b);
            // here at least b has 0 capacity
            // if b is 1 node with 0 capacity nothing we can do
            if(tsize[b] == 1) {
                cout << "no\n";
                return;
            }

            
            if(!capacity[a]) {
                // a has no capacity and b has no capacity
                // if there are extra edges in a, have to remove one to get capacity
                // otherwise b also has no removable edges, so it's impossible
                if(removableEdgesCnt(a)) {
                    remove_edge(a);
                    ++actions;
                } else if(removableEdgesCnt(b)) {
                    remove_edge(b);
                    ++actions;
                    swap(a,b);
                } else {
                    cout << "no\n";
                    return;
                }
            }

            // at this p
            if(removableEdgesCnt(b)) {
                remove_edge(b);
                join(a,b);
                actions+=2;
                pq.push(find(a));
            } else {
                /*
                    case:
                    a: (1)-(0)-(1)
                    b: (0)-(0)-(0) <- cant remove any edge without breaking connection

                    break up b:
                    b: (1) (1)-(0)

                   join a, b_1 and b_2 into a

                    a': 
                    (0)-(0)-(0)
                     |   |    
                    (0) (0)-(0) 
                */

                // capacity of 2 needed to connect with b_1 and b_2
                if(capacity[a] < 2) {
                    if(removableEdgesCnt(a)){
                        ++actions;
                        remove_edge(a);
                    }
                    else {
                        cout << "no\n";
                        return;
                    }
                }

                
                
               
               join(a, b);
               actions+=3;

               pq.push(find(a));
            }
        }
    }

    if(actions <= k) cout << "yes\n";
    else cout << "no\n";

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