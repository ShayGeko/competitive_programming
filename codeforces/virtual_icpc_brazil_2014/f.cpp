#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vi x(n);
    vector<long long> s(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }
    set <long long> sums;
    long long sum = 0;
    for(int i = 0; i < n; ++i){
        sums.insert(sum);
        s[i] = sum;
        sum+= x[i];
    }
    if(sum % 3){
        cout << 0 << "\n";
        return 0;
    }
    long long arcl = sum / 3;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if((sums.find(s[i] + arcl) != sums.end()) && (sums.find(s[i] + 2*arcl) != sums.end())) ++ans;
    }
    cout << ans << '\n';
    return 0;
}