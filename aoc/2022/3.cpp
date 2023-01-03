#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long long ll;
typedef vector<ll> vll;

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
    
    string s[3];


    int sum = 0;
    string t = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while(cin >> s[0]){
        cin >> s[1] >> s[2];
        unordered_map<char, int> a[3];

        for(int i = 0; i < 3; ++i){
            for(auto c : s[i])a[i][c]++;
        }

        for(int i = 0; i < 52; ++i){
            char c = t[i];
            if(a[0][c] && a[1][c] && a[2][c]){
                sum += i+1;
                break;
            }
        }
    }

    cout << sum << '\n';

}
int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}