#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define pf push_front
#define has(a, b) (a.find(b) != a.end())
#define imin(a, b) a = min(a, b)
#define imax(a, b) a = max(a, b)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define gpfront(x) (x).front();(x).pop_front()
#define gpback(x) (x).back();(x).pop_back()

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

istream &operator >> (istream& is, pii &p){
    is >> p.first >> p.second;
    return is;
}
ostream &operator << (ostream& os, pii &p){
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

vi nums;
void solve(){
    int num;
    while(cin >> num){
        nums.push_back(num);
    }
    // cout << sz(nums) << '\n';

    deque<pii> moved;

    int moved_cnt = 0;
    fora(i, sz(nums)) moved.eb(i, nums[i]);
    int n = sz(nums);

    fora(i, n){
        while(moved.front().first != i){
            auto k = gpfront(moved);moved.pb(k);
        }
        const auto [ind, num] = moved.front();
        
    }

    

    int sum = 0;

    int k = 0;
    fora(i, sz(moved)){
        if(moved[i].first == 0){
            k = i;break;
        }
    }
    // cout << k << '\n';
    // cout << "-----------------\n";
    for(int i = k+1000; i <= k+3000; i+=1000){
        sum+=moved[i%n].first;
        // cout << moved[i%n].first << '\n';
    }

    // for(auto t : moved){
    //     cout << t.first << " ";
    // }
    // cout << '\n';
    cout << sum << '\n';
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