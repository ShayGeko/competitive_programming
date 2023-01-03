#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii; 

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}


typedef struct segtree{
    typedef ll T;
    typedef struct node {
        int tl, tr;
        T val = 0;
        node *lnode = nullptr, *rnode = nullptr; 

        node(int l, int r) {
            tl = l;
            tr = r;
        }
        void extend() {
            if (!lnode && tl < tr) {
                int t = (tl + tr) >> 1;
                lnode = new node(tl, t);
                rnode = new node(t+1, tr);
            }
        }
        T get(int l, int r) {
            // cout << "DEBUG| " << "getting [" << l << ", " << r <<"] from a node [" << tl << ", " << tr <<"]\n";
            if(tr < l || tl > r) {
                // cout << "DEBUG| " << "OUT OF BOUNDS\n";
                return 0;
            }
            // cout << "DEBUG| " << l << " " << r << '\n';
            if(l > r) return 0;
            if(tl == l && tr == r){
                // cout << "DEBUG| " << "Success!" << '\n';
                return val;
            }
            extend();
            int m = lnode->tr;
            return max(
                lnode->get(l, min(r, m)),
                rnode->get(max(l, m + 1), r)
            );

        }
        void set(int k, T x) {
            // cout << "DEBUG| " << "[node: " << tl << " "  << tr << "] setting " << k << " to " << x << '\n';
            if(tl == tr){
                val = x;
                return;
            }
            extend();
            if(k <= lnode->tr){
                lnode->set(k, x);
            }
            else rnode->set(k,x);

            val = max(lnode->val, rnode->val);
        }
    } Node;
    Node *root = new Node(0, 1);
    int insert_cnt = 0;
    void set(int k, T x){
        // cout << "DEBUG| " << "segtree: setting " << k << " to " << x << '\n';
        // cout << "DEBUG| " << "segtree: current root: " << root->tl << " " << root->tr << '\n';
        while(k > root->tr){
            // cout << "DEBUG| " << "doubling the size\n";
            Node *new_root = new Node(0, 2 * root->tr);
            new_root->rnode = new Node(root->tr + 1, new_root->tr);
            new_root->lnode = root;
            new_root->val = root->val;
            root = new_root;
            // cout << "DEBUG| " << "success\n";
            // cout << "DEBUG| " << "new root: " << root-> tl << " " << root->tr << '\n';
        }
        
        // cout << "DEBUG| " << "segtree: updated(?) root: " << root->tl << " " << root->tr << '\n';
        root->set(k, x);
        ++insert_cnt;
    }
    void push_back(T x){
        set(insert_cnt, x);
    }
    T get(int l, int r){
        // cout << "DEBUG| segtree: received get on " << l << " " << r << '\n';
        auto res = root->get(l, r);
        
        // cout << "DEBUG: segtree: returning " << res << " for get on [" << l << ", " << r << "]\n";
        return res;
    }
    T get_best(){
        return root->val;
    }

} Segtree;

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;



void solve(){
    int n;
    cin >> n;
    vi a(n), h(n);

    for(int i = 0; i < n; ++i) cin >> h[i];
    for(int i = 0; i < n; ++i) cin >> a[i];

    vi length_dp(n, INF);
    vector<vector<pill>> beauty_dp(n);

    vector<Segtree> segmentTrees(n);

    int maxLen = 1;

    for(int i = 0; i < n; ++i){
        // cout << "DEBUG| processing element #" << i << " {" << h[i] << ", " << a[i] << "}\n"; 
        auto t = lower_bound(length_dp.begin(), length_dp.begin() + maxLen, h[i]);
        int pos = t - length_dp.begin();
        if(pos == maxLen) ++maxLen;
        // update length_dp at that index to h[i]
        *t = h[i];
        ll sum = a[i];
        // cout << "DEBUG| element #" << i << " going into pos " << pos << "\n"; 
        if(pos > 0){
            auto tt = lower_bound(beauty_dp[pos-1].rbegin(), beauty_dp[pos-1].rend(), pair<int, ll>{h[i], -1});
            int pos1 = tt - beauty_dp[pos-1].rbegin();
            int len = beauty_dp[pos-1].size();
            // cout << "DEBUG| " << "there are " << beauty_dp[pos-1].size() << " elements at previous pos\n";
            // cout << "DEBUG| " << "position from end: " << pos1 << '\n';
            // cout << "DEBUG| " << "sending a get to a segment tree at " << pos1 - 1 <<": " << len - pos1 << " " << len-1 << '\n';
            // maybe len - pos1 -1
            sum += segmentTrees[pos-1].get(len - pos1, len-1);
        }
        // cout << "DEBUG| " << "adding value " << sum << " as reachable for length " << pos + 1 << '\n';
        beauty_dp[pos].push_back(pair<int, ll>{h[i], sum});
        segmentTrees[pos].push_back(sum);
    }

    ll maxi = 0;

    // cout << "DEBUG| " << "got through the dp!\n";

    for(auto segtree : segmentTrees){
        maxi = max(maxi, segtree.get_best());
        //cout << segtree.get_best() << " ";
    }
    // cout << '\n';

    cout << maxi << endl;

}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}