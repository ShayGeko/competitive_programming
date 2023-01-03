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
template<class T>
vector<T>& operator+=(vector<T> &a, const vector<T> &b){
    assert(sz(a) == sz(b));

    fora(i, sz(b)){
        a[i] += b[i];
    }

    return a;
}
template<class T1, class T2>
pair<T1, T2>& operator+= (pair<T1, T2> &a, pair<T1, T2> &b){
    a.first += b.first;
    a.second +=b.second;

    return a;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

vector<string> grid;
void solve(){
    string s;

    while(true){
        getline(cin, s);
        if(s == "" || s == "\n") break;

        grid.pb(s);
    }

    
    pii pos = {0,0};
    vpii moves  = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vc arrows = vc{'>', 'v', '<', '^'};
    int n = sz(grid), m = sz(grid[0]);
    cout << n << " " << m << '\n';

    
    int dir = 0;
    while(cin >> s) {


    while(grid[pos.first][pos.second] != '.') ++pos.second;


    stringstream sin(s);

    int a;
    char b;
    while(sin >> a){
        
        pii next = pos + moves[dir], prev = pos;
        // a--;
        while(a > 0){
           // cout << prev[0] << " " << prev[1] << " " << arrows[dir] << " " << a << '\n';
           // cout << "trying "<< next[0] << ' ' << next[1] << '\n';
            if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= m){
               //  cout << "OUT OF BOUNDS - WRAPPING\n";
                next = {
                    (n + next.first)%n,
                    (m + next.second)%m
                };
                // cout << "AFTER WRAP: " << next[0] << " " << next[1] << '\n';
            } 
            while(next.first >= 0 && next.first < n && next.second >= 0 && next.second < m 
                && grid[next.first][next.second] == ' '){
                // cout << "Space....\n";
                next += moves[dir];
            }
            if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= m){
                // cout << "Out of board while wrapping\n";
                continue;
            } 
            if(grid[next.first][next.second] != '#'){
                    if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= m){
                        cout << "ERRORRRR\n";
                    }
                    if(prev.first < 0 || prev.first >= n || prev.second < 0 || prev.second >= m){
                        cout << "ERRORRRR\n";
                    }
                    grid[prev.first][prev.second] = arrows[dir];
                    grid[next.first][next.second] = '*';

                    prev = next;
                    next += moves[dir];
            }
            else if(grid[next.first][next.second] == '#'){
                    // cout << "HIT A WALL\n";
                    next = prev;
                    break;
            }
            a--;
        //    / cout << "Success, moved to " << prev[0] << " " << prev[1] << '\n';
            // for(auto s : grid){
            //     cout << s << '\n';
            // }
            // cout << "===========================\n";
        }

        if(!a) next = prev;
        pos = next;

        if(pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= m){
                        cout << "ERRORRRR\n";
                    }

        if(sin >> b){
            if(b == 'L'){
                dir = (4 + dir - 1) % 4;
            }
            else dir = (dir + 1) % 4;
        }
    }
    }
    cout << "done\n";
    for(auto s : grid){
        cout << s << '\n';
    }
    cout << "RESULTS: " << pos.first << " " << pos.second << " " << dir << '\n';
    cout << (ll) 1000 * (pos.first+1) + (ll) 4 * (pos.second+1) + (ll) dir << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    ifstream in("22.in");
    streambuf *cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    int t = 1;

    // cin >> t;
    
    try{
    while(t--){
        solve();
    }
    }
    catch(exception e){
        cout << e.what() << '\n';
    }
    cout.flush();
    
    return 0;
}