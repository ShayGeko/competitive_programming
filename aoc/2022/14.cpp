#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

int max_y = 0;

pii start = {500, 0};
vector<vc> grid = vector<vc>(1500, vc(600, '.'));
bool launchSand(pii v){
    int i = v.first, j = v.second;
    if(grid[i][j + 1] != '.' && grid[i-1][j+1] != '.' && grid[i+1][j+1] != '.'){
        grid[i][j] = 'o';

        // cout << "stuck at " << i << " " << j << '\n';
        if(make_pair(i, j) == start) return false;

        return true;
    }
    else if(grid[i][j + 1] == '.'){
        return launchSand({i, j+1});
    }
    else if(grid[i-1][j+1] == '.'){
        return launchSand({i-1, j+1});
    }
    else return launchSand({i+1, j+1});
}
void solve(){
    string s;

    grid[start.first][start.second] = 'o';

    
    pii from, to;
    char c;
    while(true){
        getline(cin, s);

        if(s == "") break;
        stringstream sin(s);
        sin >> to.first >> c >> to.second;

        cout << to << " | ";

        max_y = max(max_y, to.second);

        while(sin.peek() != '\n' && sin.peek() != EOF){
            from = to;
            
            sin >> c >> c;

            sin >> to.first >> c >> to.second;
            cout << to << " | ";

            max_y = max(max_y, to.second);

            int i = from.first, j = from.second;
            int i1 = to.first, j1 = to.second;
            if(i1 < i) swap(i, i1);
            if(j1 < j) swap(j, j1);
            while(i < i1 || j < j1){
                grid[i][j] = '#';
                if(i < i1) ++i;
                if(j < j1) ++j;
            }
            grid[i][j] = '#';

            c = sin.peek();
        }
        cout << '\n';
    }
    cout << "done reading\n";

    for(int i = 0; i < 1500; ++i){
        grid[i][max_y+2] = '#';
    }
    rep(j, 0, 15){
        rep(i, 490, 510){
            cout << grid[i][j];
        }
        cout << '\n';
    }
    int cnt = 1;
    while(launchSand(start)){++cnt;} 

    cout << cnt << '\n';

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