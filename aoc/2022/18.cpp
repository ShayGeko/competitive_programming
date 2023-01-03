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

set<vi> cubes;

map<vi, bool> used;
int cnt;
 vvi adj = {
        {1, 0, 0}, {0, 1, 0}, {-1, 0, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}
    };
void dfs(vi &cube){
    used[cube]=true;
    
    for(auto a : adj){
        auto ncube = cube + a;
        if(has(cubes, ncube)){
            cnt-=1;
            if(!used[ncube]) dfs(ncube);
        }
    }
    
    return;
}

int bnd = 21;
vi minbound = {0, 0, 0};
vi maxbound = {bnd, bnd, bnd};
vi as;
int mcnt = 0;
int cnt1 = 0;
void dfs1(vi &cube){
    // cout << cube[0] << " " << cube[1] << " " << cube[2] << '\n';
    used[cube]=true;
    
    for(auto a : adj){
        auto ncube = cube + a;
        if(has(cubes, ncube)){
            cnt1+=1;
        }
        else if(!used[ncube] && count(all(ncube), -2) == 0 && count(all(ncube), bnd) == 0) dfs1(ncube);
    }
    
    return;
}
void solve(){
    vi cube;

    int a, b, c;
    int maxi = -1;
    int mini = 50;
    char _;
    while(cin >> a){
        cin >> _ >> b >> _ >> c;

        imax(maxi, a);
        imax(maxi, b);
        imax(maxi, c);
        cube = {a,b,c};
        cubes.insert(cube);
    }
    cnt = 6*sz(cubes);
    cout << maxi << '\n';
    for(auto cube: cubes){
        if(!used[cube]) dfs(cube);
    }

    fora(i, bnd) fora(j, bnd) fora(k, bnd){
        vi cube = {i,j,k};
        if(!has(cubes, cube) && !used[cube]){
            // cout << "next blob\n";
            cnt1 = 0;
            dfs1(cube);
            imax(mcnt, cnt1);
        }
    }
    // sort(all(as));
    // for(auto a : as) cout << a << " ";
    // cout << '\n';
    // for(int i = 0; i < sz(as) - 1; ++i) cnt-=as[i];

    cout << cnt << " " << mcnt <<  '\n';

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