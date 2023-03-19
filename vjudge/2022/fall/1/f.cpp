#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<ull> vull;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

ull evaluate(char op, ull a, ull b){
    if(op == '+') return a + b;
    else return a*b;
}
void solve(string expr){
    stringstream ss(expr);

    vector<char> op;
    vi nums;

    int temp;
    ss >> temp;
    nums.push_back(temp);
    while(!ss.eof()){
        int num;
        char o;

        ss >> o >> num;
        op.push_back(o);
        nums.push_back(num);
    }  
    int n = nums.size();

    vector<vector<pair<ull, ull>>> dp(n, vector<pair<ull, ull>>(n));

    for(int i = 0; i < n; ++i){
        dp[i][i] = {nums[i], nums[i]};
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j = i + 1; j < n; ++j){
            ull mini = ULLONG_MAX, maxi = 0;
            for(int k = i; k < j; ++k){
                mini = min(mini, evaluate(op[k], dp[i][k].first,dp[k+1][j].first));
                maxi = max(maxi, evaluate(op[k], dp[i][k].second,dp[k+1][j].second));
            }
            dp[i][j] = {mini, maxi};
            // cout << "DEBUG| [" << i << ", " << j << "]: " << mini << " " << maxi << '\n'; 
        }
    }

    cout << dp[0][n-1].first << " " << dp[0][n-1].second << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    string expr;
    while(getline(cin, expr) && expr != "END"){
        solve(expr);
    }
    return 0;
}