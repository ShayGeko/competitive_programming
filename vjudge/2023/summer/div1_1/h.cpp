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
    string s;
    cin >> s;
    // 0. .0 . -> 0

    if(s.length() > 1) {
        int l = 0, r = sz(s)-1;

        while(l < r && s[l]=='0') ++l;

        if(s.find('.') != s.npos){
            while(r>l && s[r]=='0')r--;
        }

        s= s.substr(l, r-l+1);
    }

    
    int dot = s.find('.');
    if(dot == s.npos) dot=sz(s);
    // .000abc
    // abc.abc
    // abc

    if(dot || s.size()==1){ //
        // abc.0abc
        // abc
        // abc.
        // a0*.
        // a
        // .

        // move to s[1];
        int move = dot - 1;



        s = s.substr(0, dot) + (dot < sz(s)-1? s.substr(dot+1):"");

        
        // 100 -> 1E2
        int r = sz(s) - 1;
        while(r > 0 && s[r]=='0')r--;
        if(s.length() >= 1) {
            cout << s[0];
            if(r) {
                cout <<  '.'; rep(i, 1, r+1) cout << s[i];
            }

            if(move)cout << "E"<<move<<'\n';
            else cout << '\n';
        }
        // "."
        else cout << "0\n";
    } else {
        //.abcd
        int neg_exp = 1;
        // there is atl 1 non-zero number after dot, otherwise would've been trimmed
        while(s[neg_exp]=='0') neg_exp++;

        cout << s[neg_exp];

        if(s.size() - 1 - neg_exp) { // only print dot if there is something after
            cout << '.'; rep(i, neg_exp+1, sz(s)) cout << s[i];
        }
        cout << "E-"<<neg_exp<<'\n';
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