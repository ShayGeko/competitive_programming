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

const int maxn = 4000002;
const int INF = 2e9;
const int p = 1e9+7;


void solve(){
    string s, s1,s2;

    int r_y = 10;
    vi dist;
    vector<pii> coord;
    vector<pii> beacons;
    while(true){
        getline(cin, s);
        if(s == "") break;
        stringstream sin(s);
        char c;
        int a, b;
        sin >> s >> s >> c >> c >> a >> c;
        sin >> c >> c >> b >> c;
        sin >> s >> s >> s >> s;
        sin >> c >> c;
        int a1, b1;
        sin >> a1 >> c >> c >> c >> b1;

        // cout << a << " " << b << " " << a1 << " " << b1 << '\n';

        

        //a+= 2000000;
        // a1 += 2000000;

        coord.push_back({a, b});
        beacons.push_back({a1, b1});
        dist.push_back(abs(a - a1) + abs(b-b1));
    }

    rep(t, 0, maxn){

        int row_y = t;


        multiset<pii> coverage;
        rep(i, 0, sz(coord)){
            int x = coord[i].first, y = coord[i].second;

            int cdist = dist[i] - abs(y - t);

            if(cdist >= 0){
                coverage.insert({max(0, x-cdist), -1});
                coverage.insert({min(maxn, x+cdist), 1});
            }
        }

        int cnt = 0;
        int x = 0;
        for(auto cov : coverage){
            if(x < cov.first){
                if(cnt >= 0){
                    cout << x << " " << row_y << '\n';
                    cout << (ll)4000000*x + row_y << '\n';
                    return;
                }
                else x = cov.first;
            }
            cnt += cov.second;
            x = min(maxn, cov.first+1);
        }
    }
    int cnt = 0;
    


    cout << cnt << '\n';
    
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