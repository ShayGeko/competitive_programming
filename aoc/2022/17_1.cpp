#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define has(a, b) (a.find(b) != a.end())
#define imin(a, b) a = min(a, b)
#define imax(a, b) a = max(a, b)

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
ostream &operator << (ostream& os, vector<T> &p){
    for(auto t : p){
        os << t << " ";
    }
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

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

vector<vector<string>> rocks = {
    {
        "####"
    },
    {
        ".#.",
        "###",
        ".#."
    },
    // (0, 0) is top-left corner, not bottom-left
    {
        "###",
        "..#",
        "..#"
    },
    {
        "#",
        "#",
        "#",
        "#"
    },
    {
        "##",
        "##"
    }
};
const int n = 1000000;
vector<vector<char>> grid(4*n, vc(7, '.'));
void draw(vector<string> rock, int x, int y){
    fora(i, sz(rock)) fora(j, sz(rock[0])){
        if(rock[i][j] == '#'){
            grid[y+i][x+j] = '#';
        }
    }
}
void show(int highest){
    ford(i, highest + 5){
        cout << "|";
        fora(j, 7){
            cout << grid[i][j];
        }
        cout << "|";
        cout << '\n';
    }
    cout << "+-------+\n";
}
void solve(){
    string jets;

    cin >> jets;
    
    

    vi height_change;
    int jetpos = 0;
    int highest = 0;
    fora(i, n){
        vector<string> rock = rocks[i%5];

        int x = 2, y = highest + 3;
        bool stuck = false;

        while(!stuck){
            int dx = 0;
            
            // cout << jets[jetpos] << '\n';
            // cout << x << " " << y << '\n';
            if(jets[jetpos] == '<') dx--;
            else dx++;

            if(x + dx >= 0 && x + dx + sz(rock[0]) - 1 < 7){
                bool hit = false;
                fora(i, sz(rock) && !hit) fora(j, sz(rock[0]) && !hit){
                    if(rock[i][j] == '#' && grid[y+i][x+dx+j] == '#'){
                            hit = true;
                            dx = 0;
                    }
                }
            }
            else{
                // cout << "hit a wall\n";
                dx = 0;
            }

            x+= dx;
            int dy = -1;


            if(y+dy >= 0){
                fora(i, sz(rock) && !stuck) fora(j, sz(rock[0]) && !stuck){
                    if(rock[i][j] == '#' && grid[y+dy+i][x+j] == '#'){
                           //  cout << "hit a rock\n";
                            stuck = true;
                            dy = 0;
                    }
                }
            }
            else{
                // cout << "hit the floor\n";
                dy = 0;
                stuck = true;
            }
            y+=dy;
            jetpos = (jetpos + 1) % sz(jets);
        }

        draw(rock, x, y);

        int old_height = highest;
        imax(highest, y + sz(rock));

        height_change.pb(highest - old_height);
        // show(highest);
        if(i == 2021) cout << highest << '\n';

        int seq = 500000;
        if(sz(height_change) < 2*seq) continue;
        rep(j, 0, sz(height_change) - seq){
            bool eq = true;
            rep(k, 0, seq){
                if(height_change[j+k] != height_change[sz(height_change) - seq - 1 + k]){
                    eq = false;
                    break;
                }
            }
            if(eq){
                cout << "[" << j << ", " << j + seq << "] matches [" << sz(height_change) - seq - 1 << ", " << sz(height_change) - 1 << "]\n";
            }
        }
    }
    cout << highest << '\n';
}

int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ifstream in("17.in");
    streambuf *cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    
    return 0;
}