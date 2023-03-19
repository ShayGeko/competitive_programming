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

typedef struct {
    int id;
    int c;
    int sz;
} cube_t;

bool operator<(cube_t &a, cube_t &b){
    return a.sz < b.sz;
}
void solve(){
    int n;
    cin >> n;
    unordered_map<int, vector<cube_t>> cubes;

    rep(i, 0, n) {
        int c, sz;
        cin >> c >> sz;
        cubes[c].push_back({i, c, sz});
    }

    // maps color index to color;
    vi color_map(sz(cubes));
    // prefix sum on decreasing array of cube sizes for each color
    vector<vll> cube_prefix_sum(sz(cubes));

    
    int i = 0;
    int maxprefixsz = 0;
    // convert color to color index, sort the cube sizes and copy over
    for(auto& kv : cubes){
        sort(kv.second.rbegin(), kv.second.rend());
        cube_prefix_sum[i].resize(sz(kv.second));
        rep(j, 0, sz(kv.second)){
            cube_prefix_sum[i][j] = (kv.second)[j].sz;
        }
        color_map[i] = kv.first;
        maxprefixsz = max(maxprefixsz, sz(cube_prefix_sum[i]));
        ++i;
    }
    // compute the prefix sum for each color
    for(auto& prsum : cube_prefix_sum){
        rep(i, 1, sz(prsum)){
            prsum[i] += prsum[i-1];
        }
        maxprefixsz = max(maxprefixsz, sz(prsum));
    }

    // best match is a prefix for one color + prefix for the other
    // we can get all the ids of all cubes in a match from color indices and sizes of the prefixes

    // for each possible number of cubes, get the max and second max values from the prefix sums on this lengths
    // (i think) answer is one of:
    // a) best[i] + second_best[i]
    // b) best[i] + best[i-1]
    // c) best[i] + second_best[i-1] -- in case best[i] and best[i-1] are the same colour
    // d) second_best[i] + best[i-1] -- in case best[i] and best[i-1] are the same colour
    // best[i], second_best[i] = -1 if not reachable
    // edge_case : second_best[i] = -1, and second_best[i-1] = -1, then this size is not possible;

    vector<pair<ll, int>> best(maxprefixsz, {-1, -1}), second_best(maxprefixsz, {-1, -1});
    // get the best and second_best
    rep(j, 0, sz(cube_prefix_sum)){
        rep(i, 0, maxprefixsz){
            if(i == sz(cube_prefix_sum[j])) break;

            if(cube_prefix_sum[j][i] > best[i].first){
                second_best[i] = best[i];
                best[i] = {cube_prefix_sum[j][i], j};
            }
            else if(cube_prefix_sum[j][i] > second_best[i].first){
                second_best[i] = {cube_prefix_sum[j][i], j};
            }
        }
    }

    // i want to get the match as {color1, prefix_sz1}, {color2, prefix_sz2}

    ll max_height = 0;
    vpii color_prsize(2);

    // init with answer for prefix size 1:
    max_height = best[0].first + second_best[0].first;
    color_prsize[0] = {best[0].second, 1};
    color_prsize[1] = {second_best[0].second, 1};

    ll cur = 0;
    vpii cur_color_psize(2);
    rep(i, 1, maxprefixsz){
        ll temp;
        cur = 0;
        // case 1:
        if(second_best[i].first >= 0){
            cur = best[i].first + second_best[i].first;
            cur_color_psize[0] = {best[i].second, i+1};
            cur_color_psize[1] = {second_best[i].second, i+1};
        }
        // case 2:
        if(best[i].second != best[i-1].second){
            temp = best[i].first + best[i-1].first;
            if(temp > cur){
                cur = temp;
                cur_color_psize[0] = {best[i].second, i+1};
                cur_color_psize[1] = {best[i-1].second, i};
            }
        }
        else {
            // best[i] and best[i-1] are the same colour
            // case 3: 
           temp = best[i].first + second_best[i-1].first;
            if(temp > cur){
                cur = temp;
                cur_color_psize[0] = {best[i].second, i+1};
                cur_color_psize[1] = {second_best[i-1].second, i};
            }

            // case 4:
            temp =  second_best[i].first + best[i-1].first;
            if(temp > cur){
                cur = temp;
                cur_color_psize[0] = {second_best[i].second, i+1};
                cur_color_psize[1] = {best[i].second, i};
            }
        }

        // update best
        if(cur > max_height){
            max_height = cur;
            color_prsize = cur_color_psize;
        }

        // if second best is not reachable for prefix size i, it's not reachable for larger ones either
        if(second_best[i].first == -1){
            break;
        }
    }

    // look up colors by index
    int color1 = color_map[color_prsize[0].first];
    int color2 = color_map[color_prsize[1].first];

    // prefix size is the number of this colour's cubes used
    int n1 = color_prsize[0].second, n2 = color_prsize[1].second;

    cout << max_height << '\n';
    cout << n1 + n2 << '\n';

    i = 0;
    // print the cubes alternating by colour
    while(i < n2){
        cout << cubes[color1][i].id+1 << ' ';
        cout << cubes[color2][i].id+1 << ' ';
        ++i;
    }
    if(i < n1) cout << cubes[color1][i].id+1;
    cout << '\n';
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