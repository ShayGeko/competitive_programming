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

bool is_palindrome(string &a){
    rep(i, 0, sz(a)/2){
        if(a[i] != a[sz(a)-1 - i]) return false;
    }
    return true;
}
void solve(string a, string b){
    if(a == b){
        cout << "No solution.\n";
        return;
    }
    
    if(a.size() > b.size()) swap(a, b);

    for(int i = 0; i <= sz(a); ++i) {
        // a = abc, i = 2 ->  xa = ba
        string xa = a.substr(0, i); reverse(all(xa));
        string xb = b.substr(0, i); reverse(all(xb));

        if(xa > xb) swap(xa, xb);

        string axa = a + xa, bxa = b+xa, axb = a + xb, bxb = b+xb;
        if(is_palindrome(axa) ^ is_palindrome(bxa)) {
            cout << xa << '\n';
            return;
        }
        if(is_palindrome(axb) ^ is_palindrome(bxb)) {
            cout << xb << '\n';
            return;
        }
    }

    // no reverse prefix xa of a such that axa is palindrome but bxa isn't
    // a = abc, abccba didn't work -> bxa is always palindrome -> a is prefix of b
    // b = abc<x_palindrome_x>
    // if b[sz(a)] != 'a', acba will make axa palindrome and won't make b palindrome
    // else bcba will
    string xa = a; reverse(all(xa));
    if(b[sz(a)] == 'a') cout << 'b';
    else cout << 'a';
    cout << xa << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    string a,b;
    while(getline(cin, a)&&getline(cin, b)){
        // cout << " | " << a << " | " << b << '\n';
        solve(a, b);
    }
    cout.flush();
    
    return 0;
}