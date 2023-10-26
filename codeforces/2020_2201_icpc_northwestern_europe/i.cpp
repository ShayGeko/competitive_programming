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
    rep(i, 0, n) cin >> d[i];

    vvi t(3, vi(n));
    rep(i, 0, 3) rep(j, 0, n) cin >> t[i][j];

    vi perm = {0, 1, 2};

    do {
        int a = perm[0], b= perm[1], c = perm[2];

        auto tryPerm = [&]() {
            rep(i, 0, n) {
                rep(j, i + 2, n) {
                    vi attg(n), cttg(n);
                    attg[i] = cttg[j] = 0;

                    rep(k, 1, n) {
                        // circular prefix sum for A and C
                        attg[(i + k) % n] = attg[(i + k - 1) % n] + t[a][(i + k - 1) % n] + d[(i + k - 1) % n];
                        cttg[(j + k) % n] = cttg[(j + k - 1) % n] + t[c][(j + k - 1) % n] + d[(j + k - 1) % n];
                    }

                    bool cCollidesWithA = false;
                    rep(z, 0, n) {
                        int cur = i + z;
                        if (cur < j && cttg[cur%n] < attg[cur%n] + t[a][cur % n]) {
                             cCollidesWithA = true;
                        }
                    }
                    if(cCollidesWithA) continue;

                    auto f = [&](int m) {
                        vi bttg(n);
                        bttg[m]=0;
                        bool collideA = false, collideC = false;
                        rep(k, 0, n) {
                            int cur = m + k;
                            if(k) {
                                bttg[cur % n] = bttg[(cur - 1) % n] + t[b][(cur - 1) % n] + d[(cur - 1) % n];
                            }
                            // check for collisions
                            // collision with A if it gets to current spot before B leaves
                            if (cur < i + n && attg[cur%n] < bttg[cur%n] + t[b][cur % n]) {
                                collideA = true;
//                                break;
                            }

                            // collision with C if B gets to current spot before C leaves
                            if (cur > j && bttg[cur % n] < cttg[cur % n] + t[c][cur % n]) {
                                collideC = true;
//                                break;
                            }
                        }

                        if (collideA && collideC) {
//                            cout << "big bad\n";
                            return 2;
                        }
                        else return (int) (collideA || collideC);
                    };

                    int l = i+1, r = j-1;

                    // ternary search for position of B, codebook
                    while (r - l >= 5) {
                        int m = (r + l) / 2;

                        int f1 = f(m), f2 = f(m + 1);

                        if (f1 == 0) {
                            return make_tuple(i, m, j);
                        }

                        if (f1 >= f2) l = m;
                        else r = m + 1;
                    }
                    rep(m, l+1, r+1) {
                        int f1 = f(l), f2 = f(m);
                        if (f1 == 0) {
                            return make_tuple(i, m, j);
                        }

                        if (f1 >= f2) l = m;
                    }

                    if(f(l) == 0) {
                        return make_tuple(i, l, j);
                    }
                }
            }

            // not possible for any value of B
            return make_tuple(-1,-1,-1);
        };

        auto [posA, posB, posC] = tryPerm();
        vi pos = {posA+1, posB+1, posC+1};
        if(posA != -1) {
            cout << pos[perm[0]] << " " << pos[perm[1]] << " " << pos[perm[2]] << '\n';
            return;
        }
    } while(next_permutation(all(perm)));

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