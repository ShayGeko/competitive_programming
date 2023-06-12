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


vvi tubes;
vvi actions;
vector<multiset<int>> locations;
// move the top ball from tube i to tube j
void move_balls(int i, int j, int num){
    while(num--){
        int x = tubes[i].back();
        tubes[i].pop_back();
        tubes[j].push_back(x);
        
        locations[x].extract(i);
        locations[x].insert(j);
    
        actions.push_back({i+1, j+1});
    }
        
}
void solve(){
    int n;
    cin >> n;
    ++n;
    tubes.resize(n);
    locations.resize(n+1);
    rep(i, 0, n) {
        tubes[i].reserve(3);
    }
    int x;
    rep(i, 0, n) rep(j, 0, 3) {
        cin >> x;
        if(!x) continue;
        tubes[i].push_back(x);
        locations[x].insert(i);
    }
    vvi original_tubes = tubes;
    
    for(int i = 0; i < n-1 && sz(tubes[n-1]);++i) 
        move_balls(n-1, i, 3-sz(tubes[i]));

    rep(i, 0, n - 1){
        int colour = tubes[i][0];
        auto balls = vi(all(locations[colour]));
        assert (balls[0] == i);
        // second location in order of a ball of this color is not i
        // meaning there is only one ball of colour in this tube
        if(balls[1] != i) {
            // tube i: [c x x]
            int t = balls[1];
            // tube t: [c x x] or [x c x] or [x x c]
            while(tubes[t].back() != colour) {
                move_balls(t, n-1, 1);
            } // max 2 moves
            // tube t: [c 0 0] or [x c 0] or [x x c]
            // c is on top of bucket t
            // i has 2 trash on top
            if(tubes[n-1].size()){
                // [c x x] [x c 0] [x 0 0]
                // [c x x] [c 0 0] [x x 0]
                move_balls(t, n-1, 1);
                // t: [x 0 0] or [0 0 0]
                // last: [x c] or [x x c]
                move_balls(i, t, 2);
                // i: [c 0 0]
                // t: [x x x] or [x x 0]
                // last: [x c 0] or [x x c]
                move_balls(n-1, i, 1); // [c c 0] [(2-3)x] [(1-2)x 0]
                if(sz(tubes[n-1])==2) move_balls(n-1, t, 1);
                // [c c 0] .. [x x x] ... [x 0 0]
                // max 5 moves
            }
            else {
                // [c x x] [x x c] [0, 0, 0]
                move_balls(i, n-1, 2); //   [c 0 0] [x x c] [x x 0]
                move_balls(t, i, 1); //   [c c 0] [x x 0] [x x 0]
                move_balls(n-1, t, 1);//  [c c 0] [x x x] [x 0 0]
            }
            move_balls(n-1, i, 1);
            // at this point:
            // [c c x] [x x x] ... [0, 0, 0]
            // max 6 moves

        }
        // something might have changed
        balls = vi(all(locations[colour]));
        assert(balls[0] == i && balls[1] == i);

        // move third
        if(balls[2] != i) {
            // i: [c c x] or [c x c]
            // t: [c x x] or [x c x] or [x x c]
            if(tubes[i].back() == colour){
                // case [c t1 c] ... [0 0 0]
                // "normilize" into [c c x] ... [0 0 0]
                // only possible if didn't go into 1)
                move_balls(i+1, n-1, 1);// [c x c] [x x 0] [x 0 0]
                move_balls(i, n-1, 1);  // [c x 0] [x x 0] [x c 0]
                move_balls(i, i+1, 1);  // [c 0 0] [x x x] [x c 0] 
                move_balls(n-1, i, 2);  // [c c x] [x x x] [0 0 0]
                // 5 moves
            }
            balls = vi(all(locations[colour]));
            int t = balls[2];
            if(t != i) {
            // i: [c c x]
                if(tubes[i].back() != colour) move_balls(i, n-1, 1);
            // t: [c x x] or [x c x] or [x x c]
                while(tubes[t].back() != colour) move_balls(t, n-1, 1);
            // t: [c 0 0] or [x c 0] or [x x c]
            // last: [(1-3)x]
                move_balls(t, i, 1);
                move_balls(n-1, t, tubes[n-1].size());
            }
            // max 12 moves?
        }
    }
    cout << sz(actions) << '\n';
    for(auto x : actions){
        cout << x[0] << " " << x[1] << '\n';
        int i = x[0]-1, j = x[1]-1;
        // auto b = original_tubes[i].back();
        // original_tubes[i].pop_back();
        // original_tubes[j].push_back(b);
        // if(sz(original_tubes[j]) > 3){
        //     cout << "ERROR!\n";
        // }
    }

    // for(auto v : tubes){
    //     for(auto x : v) cout << x << " ";
    //     cout << '\n';
    // }
    return;
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