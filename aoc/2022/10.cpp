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
    vi v(1e5, 0);

    int t = 1;

    ll cnt = 1;
    string s;
    ll ans = 0;
    int a;
    int stuck = 0;
    int toAdd = 0;
    int dt = 1;
    while(true){
        //cout << t << " " << cnt << '\n';
        if(t==20 || (t - 20) % 40 == 0){
            //cout << t << " " << cnt << " " << cnt * t << '\n';
            ans+=(ll) cnt*t;
        }

        if(!stuck){
            bool read = (cin >> s) ? true:false;
            if(!read) break;
            if(s == "addx"){
                cin >> a;
                toAdd=a;
                stuck = 1;
                
            }
            if(s == "noop"){

            }
            
        }
        else {
            stuck--;
        }

       

        
        if(stuck == 0){
            cnt+=toAdd;
            toAdd = 0;
        }
        
        if(dt <= cnt + 1 && dt >= cnt - 1){
            cout << '#';
        }
        else cout << '.';

        ++t;
        ++dt;
        if(dt == 41) {dt = 1;cout << '\n';};
    }

    cout << ans << '\n';
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