#include <bits/stdc++.h>

using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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
const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

typedef struct myfuckingnode{
    vector<myfuckingnode> v;
    int num;
    bool isNum = false;
} node_t;

istream& operator >> (istream &is, node_t &v){
    cout << "reading a node\n";
    is.ignore('\n');
    char c;
    is >> c;
    while(c != ']'){
        c = is.peek();
        if(c == ']'){
            is >> c;
            return is;
        }
        
        node_t next;
        if(c == '['){
            is >> next;
        }
        else{
            int t;
            is >> t;
            next.isNum = true;
            next.num = t;
        }
        v.v.push_back(next);
        is >> c;
    }
    cout << "done reading\n";
    return is;
}
ostream& operator << (ostream &os, node_t &v){
    if(v.isNum) cout << v.num;
    else{
        cout << '[';
        rep(i, 0, sz(v.v) - 1){
            cout << v.v[i] << ',';
        }
        if(sz(v.v)) cout << v.v.back();
        cout << ']';
    }
}
bool operator== (const node_t &a, const node_t &b){
    if(a.isNum && b.isNum) return a.num == b.num;
    else if(a.isNum){
        node_t temp;
        temp.v.push_back(a);
        return temp == b;
    }
    else if(b.isNum){
        node_t temp;
        temp.v.push_back(b);
        return a == temp;
    }
    else{
        return (sz(a.v) == sz(b.v)) && a.v == b.v;
    }
}
bool operator< (const node_t &a, const node_t &b){
    if(a.isNum && b.isNum) return a.num < b.num;
    else if(a.isNum){
        node_t temp;
        temp.v.push_back(a);
        return temp < b;
    }
    else if(b.isNum){
        node_t temp;
        temp.v.push_back(b);
        return a < temp;
    }
    else{
        return a.v < b.v;
    }
}
void clear(node_t &a){
    a.v.clear();
    a.isNum = false;
}
void solve(){
    node_t a, b;

    int i = 1;
    int cnt = 0;
    while(cin >> a){
        cout << a << '\n';
        cin >> b;
        cout << b << '\n';

        if(a < b) cnt+=i;
        ++i;
        clear(a);
        clear(b);
        
        cin.ignore('\n');
    }
    cout << cnt << '\n';
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