#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}
ostream &operator << (ostream& os, pii &p){
    cout << p.first << " " << p.second;
    return os;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

void solve(){
    string s;

    vector<vc> grid;
    while(cin >> s){

        cout << s << '\n';
        vc row;

        for(auto c : s){
            row.push_back(c);
        }

        grid.push_back(row);
    }

    int n = grid.size();
    int m = grid[0].size();

    char maxi = 0;

    int cnt = 0;

    vector<vector<bool>> seen(n, vector<bool>(m, false));

    cout << "here\n";

    ll tot_maxi = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int l = 0, r = 0, u = 0, d = 0;

            for(int a = i - 1; a >= 0; a --){
                l++;
                if(grid[a][j] >= grid[i][j]) break;
            }
            for(int a = i + 1; a < m; a++){
                r++;
                if(grid[a][j] >= grid[i][j]) break;
            }
            for(int a = j - 1; a >= 0; a --){
                u++;
                if(grid[i][a] >= grid[i][j]) break;
            }
             for(int a = j + 1; a < n; a++){
                d++;
                if(grid[i][a] >= grid[i][j]) break;
            }

            tot_maxi = max((ll)l*r*u*d, tot_maxi);
        }
    }

    cout << tot_maxi << endl;

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