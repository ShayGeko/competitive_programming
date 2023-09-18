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

void solve(){
    int n, m;
    ll d;
    cin >> n >> m >> d;
    vi nums(n);
    rep(i, 0, n) cin >> nums[i];

    priority_queue<int, vi, greater<>> pq;

    int last = 0;
    ll cursum = 0, ans = 0;
    rep(i, 0, n) {
        if(nums[i] <= 0) continue;
        if(pq.size() < m) {
            cursum += nums[i];
            ans = max(ans, cursum - d*(i+1));
            pq.push(nums[i]);
        } else {
            auto cost = pq.top();
            if(nums[i] > cost) {
                cursum = cursum - cost + nums[i];
                pq.pop();
                pq.push(nums[i]);
                ans = max(ans, cursum - d*(i+1));
            }
        }
    }

    cout << ans << '\n';
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