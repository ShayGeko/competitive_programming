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
    int n;
    cin >> n;
    vi d(n);
    vvi t(3, vi(n));

    rep(i, 0, n) cin >> d[i];
    rep(i, 0, 3) rep(j, 0, n) cin >> t[i][j];

    vector<vector<vector<vb>>> collides(3, vector<vector<vb>>(3, vector<vb>(n, vb(n, false))));
    // pre-compute if each pair collides
    vpii pairs ={{0,1}, {0, 2}, {1,2}, {1, 0}, {2, 0}, {2, 1}};
    for(auto [a, b] : pairs) {
        rep(i, 0, n) rep(j, i+1, n) {
            vi getTo1(n), getTo2(n);
            getTo1[i] = getTo2[j] = 0;

            rep(z, 1, n) {
                // circular prefix sum
                getTo1[(i+z)%n] = getTo1[(i+z-1)%n] + t[a][(i+z-1)%n] + d[(i+z-1)%n];
                getTo2[(j+z)%n] = getTo2[(j+z-1)%n] + t[b][(j+z-1)%n] + d[(j+z-1)%n];
            }


            rep(z, 0, n) {
                int cur = (i+z), curmod=  (i+z)%n;

                // check if 1 bumps into 2
                if(cur >= j && getTo1[curmod] < getTo2[curmod] + t[b][curmod]) {
                    collides[a][b][i][j] = true;
                    collides[b][a][j][i] = true;
                    break;
                }
                // check if 2 bumps into 1
                else if (curmod >= i && cur < j && getTo2[curmod] < getTo1[curmod] + t[a][curmod]) {
                    collides[a][b][i][j] = true;
                    collides[b][a][j][i] = true;
                    break;
                }
            }
        }
    }

    rep(i, 0, n) {
        rep(j, 0, n) {
            if(i==j)continue;
            rep(k, 0, n) {
                if(i==k || j==k) continue;

                if(!collides[0][1][i][j] && !collides[1][2][j][k] && !collides[2][0][k][i]) {
                    cout << i+1 << " " << j + 1 << " " << k + 1 << '\n';
                    return;
                }
            }
        }
    }

    cout << "impossible\n";
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
/*
 *
 *
6
1 1 1 1 1 1
2 1 3 2 3 1
8 7 4 9 7 2
7 6 2 9 2 1

4
1 1 1 1
1 1 1 1
10 3 2 1
4 2 5 1
 */