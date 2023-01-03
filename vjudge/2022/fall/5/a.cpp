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

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
void solve(){
    string str;
    cin >> str;
    int n = str.length();

    vi divisors;

    for(int i = 1; i <= n; ++i){
        if(n % i == 0) divisors.push_back(i);
    }

    bool found = false;
    int k = 0;

    while(k < divisors.size()){
        int cur = divisors[k];
        string cur_str = str.substr(0, cur);
        bool ok = true;
        for(int i = 1; i < n / cur; ++i){
            string next = str.substr(i*cur, cur);
            if(next != cur_str.back() + cur_str.substr(0, cur_str.length() - 1)){
                ok = false;
                break;
            }
            cur_str = next;
        }
        if(ok) break;
        else ++k;
    }

    cout << divisors[k] << '\n';
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