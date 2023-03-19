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
vll prsum;
int n;
void solve(){
    cin >> n;

    vi nums(n);

    fora(i, n) cin >> nums[i];

    sort(all(nums));

    prsum.resize(n);
    prsum[0] = nums[0];
    rep(i, 1, n){
        prsum[i] = prsum[i-1] + nums[i];
    }


    // sum to the left >= sum to the right -> breaking point
    int l = 0, r = n - 1;

    // find the "decision maker"
    int first_k = -1;
    fora(i, n){
        if(prsum[i] >= prsum[n-1] - prsum[i]){
            first_k = i; break;
        }
    }
    
    if(first_k == n - 1){
        cout << 1 << '\n';
        return;
    }

    vb neededToStrongerGuys(n, false);
    vi weakestNeededToSurvive(n, -1);

    l = n - 1;

    int weakestSurvivor = first_k;
    for(int i = n - 1; i >= first_k; i--) {
        if(neededToStrongerGuys[i]) continue;

        while(l > 0 && prsum[i] - prsum[l-1] < prsum[n-1] - prsum[i]) {
            neededToStrongerGuys[--l] = true;
        }

        weakestNeededToSurvive[i] = l;
        if(l < i) 
            neededToStrongerGuys[l] = true;
        imin(weakestSurvivor, l);
    }


    cout << n - weakestSurvivor << '\n';
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