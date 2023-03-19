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
    vector<string> sv;
    string s;
    while(cin >> s){
        sv.push_back(s);
    }

    cout << "done reading" << endl;
    vector<bool> vb1(sv.size(), true), vb2(sv.size(), true);
    int l = sv[0].length();

    int cnt1[2] = {0,0}, cnt2[2] = {0,0};

    for(int i = 0; i < l; ++i){
        cout << i << endl;
        cnt1[0]=cnt1[1]=cnt2[0]=cnt2[1] = 0;
        for(int j = 0; j < sv.size(); ++j){
            if(vb1[j]){
                cnt1[sv[j][i]-'0']++;
            }
            if(vb2[j]){
                cnt2[sv[j][i]-'0']++;
            }
        }

        char c1 = cnt1[0] > cnt1[1] ? '0':'1';
        char c2 = (cnt2[0] <= cnt2[1]) ? '0':'1';

        // cout << i << " " << c1 << " " << c2 << '\n';
        if(cnt2[0] == 0) c2 = '1';
        else if(cnt2[1] == 0) c2 = '0';

        for(int j = 0; j < sv.size(); ++j){
            if(sv[j][i] != c1) vb1[j] = false;
            if(sv[j][i] != c2) vb2[j] = false;
        }

        // for(int j = 0; j < sv.size(); ++j){
        //     if(vb1[j]) cout << sv[j] << " ";
        // }
        // cout << '\n';
        // for(int j = 0; j < sv.size(); ++j){
        //     if(vb2[j]) cout << sv[j] << " ";
        // }
        // cout << "\n\n";

        ++i;
    }
    cout << "done reading1" << endl;
    string a, b;
    for(int i = 0; i < sv.size(); ++i){
        if(vb1[i]) a = sv[i];
        if(vb2[i]) b = sv[i];
    }
    cout << a << " " << b << '\n';

    ll na = 0, nb = 0;
    int k = 1;
    for(int i = l - 1; i >= 0; i--, k<<=1){
        if(a[i] == '1') na+=k;
        if(b[i] == '1') nb +=k;
    }
    cout << na << " " << nb << '\n';
    cout << na * nb << '\n';

    cout << endl;
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