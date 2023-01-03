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
    int n;
    cin >> n;
    vector<string> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    bool success = false;
    for(int i = 1; !success && i < nums.size(); ++i){
        string a = nums[i-1], b = nums[i];
        if(nums[i].size() > nums[i-1].size()) continue;
        else if(b.size() == 1 && a != "0"){
            b = "0";
            success = true;
        }
        else if(a[0] > '1'){
            b[0] = '1';
            success = true;
        }
        else if(b[0] < '9'){
            a[0] = '9';
            success = true;
        }
        // a[0] = 1, b[0] = 9
        else{
            a[0] = '9';
            if(stoll(a) > stoll(b)) success = true;
        }

        if(success){
            nums[i-1] = a;
            nums[i] = b;
        }
    }
    
    if(success){
        for(auto num : nums){
            cout << num << " ";
        }
        cout << '\n';
    }        
    else cout << "impossible\n";
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