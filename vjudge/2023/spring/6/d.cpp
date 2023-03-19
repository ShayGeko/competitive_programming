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
typedef vector<bool> vb;
typedef vector<ll> vll;

typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vb> vvb;
typedef vector<vc> vvc;

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

vector<pii> bars = {
    {1, 2},
    {2, 1},
    {2, 2}
};
void set_color (vvc &grid, int i, int j, int type){
    set<char> colors({'a','b','c','d','e'});
    auto bar = bars[type];

    fora(i1, bar.first) fora(j1, bar.second) {
        if(i > 0 && i1 == 0){
            colors.erase(grid[i-1][j+j1]);
        }
        if(j > 0 && j1 == 0){
            colors.erase(grid[i+i1][j-1]);
        }
    }

    fora(i1, bar.first) fora(j1, bar.second) {
        grid[i+i1][j+j1] = *(colors.begin());
    }


}
void solve(){
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    vvc grid(n, vc(m));
    if(m % 2 && n % 2){
        cout << "IMPOSSIBLE\n";
        return;
    }
    if(m % 2){
        if(b < n/2){
            cout << "IMPOSSIBLE\n";
            return;
        }
        b -= n/2;
        fora(i, n / 2){
            grid[2*i][0] = grid[2*i+1][0] = 'a' + i%2;
        }
    }
    if(n % 2){
        if(a < m/2){
            cout << "IMPOSSIBLE\n";
            return;
        }
        a -= m/2;
        fora(i, m / 2){
            grid[0][2*i] = grid[0][2*i+1] = 'a' + i%2;
        }
    }
    for(int i = n%2; i < n - 1; i+=2){
        for(int j = m%2; j < m - 1; j+=2){
            if(a >= 2){
                set_color(grid, i, j, 0);
                set_color(grid, i+1, j, 0);
                a-=2;
            }
            else if(b >= 2){
                set_color(grid, i, j, 1);
                set_color(grid, i, j + 1, 1);
                b-=2;
            }
            else if(c){
                set_color(grid, i, j, 2);
                c--;
            }
            else{
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }

    for(auto row : grid){
        for(auto c: row){
            cout << c;
        }
        cout << '\n';
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