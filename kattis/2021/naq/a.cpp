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
    string n;
    cin >> n;
    set<char> nums({'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});
    for(auto c : n) nums.erase(c);

    string sm, gr;
    if(nums.size() == 0){
        cout << "Impossible" << '\n';
        return;
    }
    
    char smallest = *(nums.begin()), largest = *(nums.rbegin());
    if(largest == '0'){
        cout << "0\n";
        return;
    }
    else if(n == "0"){
        cout << "1\n";
        return;
    }

    auto sm_iter = nums.lower_bound(n[0]);
    auto gr_iter = nums.upper_bound(n[0]);

    if(*sm_iter != *(sm.begin())) sm_iter--;
    // take k-1 if key and the only smaller than first is 0 or if there is no smaller than first
    if(sz(n) > 1 && (gr_iter == nums.begin() || *sm_iter == '0')){
        fora(i, sz(n) - 1) sm += largest;
    }
    else {
        sm += *sm_iter;
        fora(i, sz(n) -1) sm += largest;
    }

    // take k+1 if there is no greater than first
    if(gr_iter == nums.end()){
        gr += *(nums.upper_bound('0'));
        fora(i, sz(n)) gr += smallest;
    }
    else{
        gr += *gr_iter;
        fora(i, sz(n)-1) gr += smallest;
    }

    ll dist_sm = stoll(n) - stoll(sm);
    ll dist_gr = stoll(gr) - stoll(n);

    if(dist_sm <= dist_gr) cout << sm << " ";
    if(dist_gr <= dist_sm) cout << gr;
    cout << '\n';
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