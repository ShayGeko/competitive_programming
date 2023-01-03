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
typedef unsigned long long ull;

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

typedef struct node {
    bool isNum = false;
    char op;
    ull val;
    string name;
    string left = "";
    string right = "";
    string strval = "";
} node_t;

iostream& operator >>(iostream &is, node_t &v){
    char c;
    is >> v.name;
    v.name = v.name.substr(0,4);
    is >> c;
    is.putback(c);
    if(isdigit(c)){
        v.isNum = true;
        is >> v.val;
    }
    else{
        is >> v.left >> v.op >> v.right;
    }

    return is;
}

unordered_map<string, node_t> nodes;

ull compute(ull a, ull b, char op){
    if(op == '+') return a + b;
    else if(op == '*') return a*b;
    else if(op == '-') return a-b;
    else if(op == '/') return a/b;

    return a;
}
ull get(node_t &v){
    if(v.isNum) return v.val;

    ull left = get(nodes[v.left]);
    ull right = get(nodes[v.right]);

    v.isNum = true;
    v.val = compute(left, right, v.op);

    return v.val;
}

string getExpr(node_t &v){
    if(v.name == "root") return getExpr(nodes[v.left]) + '=' + getExpr(nodes[v.right]);
    else if(v.name == "humn") {v.strval = "humn"; return "humn";}
    else{
        if(v.strval != "") return v.strval;

        if(v.isNum){
            v.strval = to_string(v.val);
            return v.strval;
        }
        string lstr, rstr;
        lstr = getExpr(nodes[v.left]);
        rstr = getExpr(nodes[v.right]);
        string humn = "humn";
        bool gleft = lstr.find(humn.c_str()) == lstr.npos, gright = rstr.find(humn.c_str()) == rstr.npos;

        // cout << v.name << " " << gleft << " " << gright << '\n';
        if(gleft && gright){
            v.strval = to_string(get(v));
            // cout << v.strval << '\n';
            return v.strval;
        }
        else if(gleft){
            lstr = to_string(get(nodes[v.left]));
        }
        else if(gright){
            rstr = to_string(get(nodes[v.right]));
        }
        v.strval = "("+lstr+")" + v.op + "("+rstr+")";
        return v.strval;
    }
}

char reverseOp(char op){
    if(op == '+') return '-';
    else if(op == '*') return '/';
    else if(op == '-') return '+';
    else return '*';
}
void solve1(){
     cout << get(nodes["root"]) << '\n';
}
void solve2(){
    node_t root = nodes["root"];
    
    nodes["humn"].isNum = false;
    node_t left = nodes[root.left], right = nodes[root.right];

    getExpr(left);
    getExpr(right);
    if(left.isNum) swap(left, right);

    ull val = right.val;

    auto cur = left;
    while(cur.name != "humn"){
        left = nodes[cur.left], right = nodes[cur.right];
        if(left.isNum && cur.op == '/') {
            // a / expr(hum) = b
            // b * expr(hum) = a
            cout << "DIVISION PRESENT\n";
            val = (double) left.val / val;
            cur = right;

            cout << cur.strval << " = " << val << '\n';
            continue;
        }
        if(left.isNum) swap(left, right);

        cout << cur.strval << " = " << val << '\n';
        val = compute(val, right.val, reverseOp(cur.op));
        cur = left;
    }
    cout << cur.strval << " = " << val << '\n';

    cout << val << '\n';
}
void solve(){
    string s;
    while(true){
        getline(cin, s);
        if(s == "") break;

        node_t v;
        stringstream sin(s);
        sin >> v;
        nodes[v.name] = v;
    }

    solve2();
}

int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);//cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    
    return 0;
}