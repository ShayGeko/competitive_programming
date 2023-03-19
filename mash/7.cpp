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

vector<int> nimber(33, -1);
int getMex(unordered_set<int> &mex){
    for(int i = 0; i <= sz(mex)+5; ++i){
        if(!mex.count(i)){
            return i;
        }
    }
}
int get(unsigned int a){
    if(nimber[a] > -1) {
        return nimber[a];
    }
    
    //cout << "solving " << a << '\n';

    unordered_set<int> mex;
    mex.insert(get(a-1));
    rep(i, 1, a){
        int left = get(i), right = get(a - 1 - i);
        // cout << "left: nimber for " << i << " is " << left << '\n';
        // cout << "right: nimber for " << a - 1 - i << " is " << right << '\n';
        //cout << (left ^ right) << '\n';
        mex.insert(left^right);
    }
    
    

    nimber[a] = getMex(mex);
    //cout << "Solved " << a << ". Answer: " << nimber[a] << '\n';
    return nimber[a];
}
void solve(){
    string s;
    cin >> s;

    int a = 0;

    vector<int> runs;


    int cur = 0;
    bool isRun = false;
    s += '.';
    forc(c, s){
        if(c == '!'){
            if(isRun) ++cur;
            else {
                isRun = true;
                cur = 1;
            }
        }
        else{
            if(isRun){
                runs.push_back(cur);
                cur = 0;
                isRun = false;
            }
        }
    }
    int ans = 0;
    
    nimber[0] = 0;
    nimber[1] = 0;

    unordered_set<int> mex;
    ans = 0;
    for(auto game : runs) {
        ans ^= get(game);
    }


    if(ans > 0) cout << "Bob\n";
    else cout << "Alice\n";

}

int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    
    return 0;
}