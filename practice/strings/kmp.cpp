#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;

const int maxn = 1e5;
const int INF = 1e9;

void solve(){
    string s;
    cin >> s;

    vi kmp(s.length(), 0);

    int k = 0;
    for(int i = 1; i < s.length(); ++i){
        k = kmp[i-1];
        if(s[k] == s[i]){
            kmp[i] = kmp[i-1]+1;
        }
        else{
            while(k && s[k]!=s[i]) k = kmp[k-1];
            if(s[k]==s[i])++k;
            kmp[i]=k;
        }
    }
    for(int i = 0; i < s.length(); ++i){
        cout << kmp[i] << " ";
    }
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