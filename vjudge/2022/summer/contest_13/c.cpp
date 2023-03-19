#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;


vector<double> nums;
double solve(string &s, int &i){
    double sum = 0;
    bool typeKnown = false;
    bool type = true;
    if(s[i] == '(') ++i;
    for(; i < s.length(); ++i){
        if(s[i]=='R'){
            int k = s[i+1]-'0';
            sum+= type? nums[k-1] : 1./nums[k-1];
            i++;
        }
        else if(s[i] == '('){
            sum += type? solve(s, i) : 1./solve(s, i);
        }
        else if(s[i] == ')'){
            return type? sum : 1. / sum;
        }
        else if(!typeKnown){
            type = !(s[i] == '|');
            typeKnown = true;
            if(!type) sum = 1./sum;
        }
    }
    return type? sum : 1. / sum;
}
void solve(){
    string s;
    int n;
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    cin >> s;
    int i = 0;
    cout << fixed << setprecision(5) << solve(s, i) << '\n';
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