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

vector<string> a(1, "####");
vector<string> b = {
    ".#.",
    "###",
    ".#."
};
vector<string> c = {
    "###",
    "..#",
    "..#"
};
vector<string> d = {
    "#",
    "#",
    "#",
    "#"
};
vector<string> e = {
    "##",
    "##"
};
vector<vc> grid(20000, vc(7, '.'));

void draw(vector<string> &r, int x, int y){
    // cout << "drawing at " << y << " " << x << '\n'; 
    for(int i = 0; i < sz(r); i++){
        rep(j, 0, sz(r[0])){
            if(r[i][j] == '#') grid[y+i][x+j] = '#';
        }
    }
}
void clear(vector<string> &r, int x, int y){
    // cout << "drawing at " << y << " " << x << '\n'; 
    for(int i = 0; i < sz(r); i++){
        rep(j, 0, sz(r[0])){
            if(r[i][j] == '#') grid[y+i][x+j] = '.';
        }
    }
}
void print(int highest){
    for(int i = highest + 5; i>= 0; i--){
        rep(j, 0, 7){
            cout << grid[i][j];
        }
        cout << '\n';
    }
}
void solve(){
    vector<vector<string>> rocks = {a,b,c,d,e};

    int sx = 2;
    int highest = 0;
    string jets = "", s;
    while(cin >> s){
        jets += s;
    }

    cout << jets << '\n';
    cout << (jets.find(' ') == jets.npos) << " " << (jets.find('\n') == jets.npos) << '\n';

    int cnt = 0;

    int n = jets.size();
    int jetpos = 0;

    while(cnt < 2022){
        // cout << "rock #" << cnt%5 << '\n';
        auto rock = rocks[cnt%5];

        int cy = highest + 3, cx = sx;
        // cout << cy << " " << cx << '\n';
        
        bool stuck = false;

        int dx=0, dy=0;
        while(!stuck){
            // draw(rock, cx, cy);
            // print(highest);
            // clear(rock, cx, cy);
            // cout << "-------------\n";
            // cout << jets[jetpos] << '\n';
            if(jets[jetpos] == '<')
                dx--;
            else dx++;
            if(cx + dx >= 0 && cx + dx + rock[0].size() - 1 < 7){
                bool br = false;
                for(int i = 0; i < sz(rock) && !br; i++){
                    for(int j = 0; j < sz(rock[0]) && !br; ++j){
                        if(rock[i][j] == '#' && grid[cy+dy+i][cx+dx+j] == '#'){
                            dx = 0;
                            //cout << "hit a rock\n";
                            br = true;
                        }
                    }
                }
            }
            else{
                dx = 0;
                //cout << "hit a wall\n";
            }
            dy--;
            if(cy + dy < 0) {
                stuck = true;
                 dy = 0;
                //cout << "cancel drop - hit floor\n";
            }
            for(int i = 0; i < sz(rock) && !stuck; i++){
                for(int j = 0; j < sz(rock[0]) && !stuck; ++j){
                    if(rock[i][j] == '#' && grid[cy+dy+i][cx+dx+j] == '#'){
                        //cout << "cancel drop - hit a rock\n";
                        dy = 0;
                        stuck = true;
                    }
                }
            }
            cx += dx;
            cy += dy;
            dx = dy = 0;
            jetpos = (jetpos+1)%n;
        }
        // cout << "drawing rock #" << cnt%5 << " at " << cy << " " << cx << '\n'; 
        draw(rock, cx, cy);
        
        imax(highest, cy + sz(rock));

        // print(highest);
        // cout << "==================\n";
        ++cnt;
    }

    
    print(highest);
    cout << highest << '\n';
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