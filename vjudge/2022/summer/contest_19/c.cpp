#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

void printBigInt(string &a){
    int b = a.size() - 1;

    string mantissa = a.substr(1);
    a = a[0];
    int end = mantissa.find_last_not_of('0');
    // 1.00E2 -> 1E2
    if(end == mantissa.npos) {cout << a + "E" << b << '\n'; return;}
    mantissa = mantissa.substr(0, end+1);
    
    cout << a + "." + mantissa + "E" << b << '\n';
    return;
}
void solve(){
    // to whoever is reading this code, dont lol
    string s;
    cin >> s;
    int start = s.find_first_not_of('0');

    
    // all zeroes
    if(start == s.npos) {cout << 0 << '\n'; return;}

    s = s.substr(start);
    
    int dotpos = s.find_first_of('.');
    
    // integer part
    string a = s.substr(0, dotpos);

    // integer.{} or integer
    if(dotpos == s.npos || dotpos == s.size() - 1){
        if(a.size() > 1){
            printBigInt(a);
            return;
        }
        if(a.size() > 0) cout << a << '\n';
        else cout << 0 << '\n';

        return;
    }

    string mantissa = s.substr(dotpos+1);

    // remove 0's at the end
    int end = mantissa.find_last_not_of('0');
    mantissa = mantissa.substr(0, end + 1);

    // 0*.mantissa -> m.antissaE(-k)
    if(dotpos == 0) {
        int shiftleft = mantissa.find_first_not_of('0');
        // .0* -> 0
        if(shiftleft == mantissa.npos) { cout << "0"; return;}

        // 0.(0)*k -> 0.k
        mantissa = mantissa.substr(shiftleft);
        // .abcd -> a = a, mantissa = bcd
        a = mantissa[0];
        mantissa = mantissa.substr(1);
        // .k -> k. -> kE-1
        if(mantissa.size() == 0){
            cout << a + "E" << -1 << '\n';
            return;
        }

        // +(shiftLeft) for 0.0*k to 0.k,  +1 for 0.k{..} -> k.{..}
        int b= (shiftleft) + 1;

        cout << a + "." + mantissa + "E" << -b << '\n';
        return;
    }
    
    // a = k(?)* mantissa = (?)*

    // k(?)*.{}
    if(mantissa.size() == 0){
        if(a.size() > 1){
            printBigInt(a);
            return;
        }
    }

    if(a.size() > 1){
        int b = a.size() - 1;
        mantissa = a.substr(1) + mantissa;
        a = a[0];
        cout << a + "." + mantissa + "E" << b << '\n';
        return;

    }

    cout << a + '.' + mantissa << '\n';

}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}