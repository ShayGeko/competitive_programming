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
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &x : nums) cin >> x;

    // number of subsequences so far matching 
    // 0: 1
    // 1: 1 2 [2*]
    // 2: 1 2 [2*] 3
    vvi dp(n+1, vi(3));

    dp[0] = {0,0,0};

    rep(i, 1, n+1){
        dp[i] = dp[i-1];
        
        if(nums[i-1] == 1) dp[i][0] = (dp[i-1][0]+1)%p;
        else if(nums[i-1] == 2) {
            // If taking at least one of the previous two's there is now twice as many combinations
            // If this is the only 2, there is (#-of-ones-so-far) ways to take it
            dp[i][1] = ((2*dp[i-1][1])%p + dp[i-1][0])%p;
        }
        else {
            dp[i][2] = (dp[i-1][2] + dp[i-1][1])%p;
        }
    }

    cout << dp[n][2] << '\n';

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