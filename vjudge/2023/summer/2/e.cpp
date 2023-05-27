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


typedef struct node {
    int val;
    vector<node*> children;
} node_t;


node_t* readNode(stringstream &ss){
    node_t* node = new node_t();
    char throwaway;
    while(ss.peek() == ' ') ss >> throwaway;
    ss >> (node->val);
    while(ss.peek() == ' ') {
        throwaway = ss.get();
    }
    while(ss.peek() == '('){
        // read '('
        ss >> throwaway;
        while(ss.peek() == ' ') throwaway = ss.get();

        (node->children).push_back(readNode(ss));

        while(ss.peek() == ' ') throwaway = ss.get();
        // read ')'
        ss >> throwaway;
        while(ss.peek() == ' ') throwaway = ss.get();
    }

    return node;
}
bool areSimilar(node_t*a, node_t*b){
    if((a == NULL) ^ (b == NULL)) return false;
    if(a == NULL) return true;
    if(a->val != b->val) return false;

    if(a->children.size() != b->children.size()) return false;

    sort(all(a->children), [](node_t* a, node_t*b){return a->val < b->val;});
    sort(all(b->children), [](node_t* a, node_t*b){return a->val < b->val;});

    rep(i, 0, sz(a->children)){
        if(!areSimilar(a->children[i], b->children[i])) return false;
    }

    return true;
}
void solve(){
    string s1, s2;
    getline(cin, s1);
    stringstream ss(s1);

    node_t* a = readNode(ss);
    getline(cin, s2);
    ss = stringstream(s2);
    node_t* b = readNode(ss);

    bool ans = areSimilar(a, b);

    if(ans) cout << "Yes\n";
    else cout << "No\n";
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