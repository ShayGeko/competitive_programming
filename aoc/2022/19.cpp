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

struct blueprint{
    int bp;
    int ore;
    int clay;
    int obs_ore;
    int obs_clay;
    int g_ore;
    int g_obs;
};

ostream &operator << (ostream& os, blueprint &p){
    os << p.bp << " " << p.ore << " " << p.clay << " " << p.obs_ore << " " << p.obs_clay << " " << p.g_ore << " " << p.g_obs;
    return os;
}

typedef struct _ {
    int step;
    int ore;
    int clay;
    int obsid;
    int ore_r;
    int clay_r;
    int obs_r;
    int geode_r;
    int geode;
} state;
bool greater1(const state&a, const state&b){
    vi av = {a.geode, a.geode_r, a.obsid, a.obs_r, a.clay, a.clay_r, a.ore, a.ore_r};
    
    vi bv = {b.geode, b.geode_r, b.obsid, b.obs_r, b.clay, b.clay_r, b.ore, b.ore_r};
    return av > bv;
}
bool less1(const state&a, const state&b){
    vi av = {a.geode, a.geode_r, a.obsid, a.obs_r, a.clay, a.clay_r, a.ore, a.ore_r};
    
    vi bv = {b.geode, b.geode_r, b.obsid, b.obs_r, b.clay, b.clay_r, b.ore, b.ore_r};
    return av < bv;
}
bool operator> (const state&a, const state&b){
    return greater1(a,b);
}
bool operator< (const state&a, const state&b){
    return less1(a, b);
}
bool operator== (const state&a, const state&b){
    return a.step == b.step && a.ore == b.ore && a.ore_r == b.ore_r && a.clay == b.clay && a.clay_r == b.clay_r 
    && a.geode == b.geode && a.geode_r == b.geode_r && a.obs_r == b.obs_r && a.obsid == b.obsid;
}

blueprint bp;

int max_ore, max_clay, max_obs;
void updateModifiers(){
    max_ore = max(max(bp.clay, bp.obs_ore), bp.g_ore);
    max_clay = bp.obs_clay;
    max_obs = bp.g_obs;
}
ostream &operator << (ostream& os, const state &p){
    os << "STATE: " << p.step << " " 
        << "ore: " << p.ore << " " << p.ore_r << " "
        << "clay: " << p.clay << " " << p.clay_r << " " 
        << "obsidian: " << p.obsid << " " << p.obs_r << " " 
        <<  "geode: " << p.geode << " " << p.geode_r;
    return os;
}
state getNext(state b){
    state a = b;
    a.step++;
    a.ore += a.ore_r;
    a.clay += a.clay_r;
    a.obsid += a.obs_r;
    a.geode += a.geode_r;

    return a;
}

unordered_map<state, bool> used;
int getBest(blueprint bp, int T){
    state init_state = {0, 0, 0, 0, 1, 0, 0, 0};
    auto [a1, b1, c1, d1] = {0, 0, 0, 0};
    queue<state> pq;
    used.clear();
    pq.push(init_state);

    used[init_state] = true;

    int maxi = 0;
    while(!pq.empty()){
        auto cur = pq.front();
        // cout << cur << '\n';
        pq.pop();
        if(cur.step == T){
            if(maxi < cur.geode){
                maxi = cur.geode;
            }
            continue;
        }

        state next = getNext(cur);
        if(used[next]){
            pq.push(next);
            used[next] = true;
        }
        if(cur.ore >= bp.ore && cur.ore_r < max_ore){
            state next = getNext(cur);
            next.ore-=bp.ore;
            next.ore_r++;
            if(!used[next]){
                pq.push(next);
                used[next]=true;
            }
        }
        if(cur.ore >= bp.clay && cur.clay_r < max_clay){
            state next = getNext(cur);
            next.ore-=bp.clay;
            next.clay_r++;
            if(!used[next]){
                pq.push(next);
                used[next]=true;
            }
        }
        if(cur.ore >= bp.obs_ore && cur.clay >= bp.obs_clay && cur.obs_r < max_obs){
            state next = getNext(cur);
            next.ore-=bp.obs_ore;
            next.clay-=bp.obs_clay;
            next.obs_r++;
            if(!used[next]){
                pq.push(next);
                used[next]=true;
            }
        }
        if(cur.ore >= bp.g_ore && cur.obsid >= bp.g_obs){
            state next = getNext(cur);
            next.ore-=bp.g_ore;
            next.obsid-=bp.g_obs;
            next.geode_r++;
            if(!used[next]){
                pq.push(next);
                used[next]=true;
            }
        }
        

        if(used.size() % 1000000 == 0){
            cout << "looked at: " <<  used.size() << " states" << '\n';
            cout << maxi << '\n';
        }
    }

    cout << "done\n";
    cout << "looked at: " <<  used.size() << " states" << '\n';
    cout << pq.size() << '\n';
    return maxi;
}
void solve(){
    string s;
    int num, ore, clay;
    pii obs, geode;
    while(
        scanf("Blueprint %d: Each ore robot costs %d ore. Each clay robot costs %d ore. Each obsidian robot costs %d ore and %d clay. Each geode robot costs %d ore and %d obsidian.\n",
     &num, &ore, &clay, &obs.first, &obs.second, &geode.first, &geode.second) == 7){

        bp = {num, ore, clay, obs.first, obs.second, geode.first, geode.second};
       
        updateModifiers();


        // state: {step, blueprint, #ore, #clay, #obsidian, #ore_r, #clay_r, #obs_r, #geode_r} -> geode; maximize geode at step 24
        // 

        cout << bp << " " << getBest(bp) << '\n';        
    }
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