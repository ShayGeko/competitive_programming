#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 1e9;

void solve(){
    vector<char> items;
    string s;
    cin >> s;
    bool fail = false;
    for(auto c : s){
        switch(c){
            case '$':
            case '|':
            case '*':
             items.push_back(c);
            break;
            case 't':{
                if(!items.size() || items.back()!='|'){
                    cout << "NO\n";
                    return;
                }
                items.pop_back();
            }
            break;
            case 'j': {
                if(!items.size() ||items.back()!='*'){
                    cout << "NO\n";
                    return;
                }
                items.pop_back();
            }
            break;
            case 'b': {
                if(!items.size() || items.back()!='$'){
                    cout << "NO\n";
                    return;
                }
                items.pop_back();
            }
            default:
            break;
        }
    }
    if(items.size() == 0) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}