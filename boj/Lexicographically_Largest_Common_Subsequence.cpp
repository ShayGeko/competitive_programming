#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m;
    cin >> n;
    vi A(n);
    for(auto &x : A) cin >> x;
    cin >> m;
    vi B(m);
    for(auto &x : B) cin >>x;


    
    vector<pii> sa(n), sb(m);
    rep(i, 0, n) {
        sa[i] = {A[i], -i};
    }
    rep(i, 0, m) sb[i] = {B[i], -i};
    sort(sb.rbegin(), sb.rend());
    sort(sa.rbegin(), sa.rend());

    // for(auto [a, b] : sa) {
    //     cout << "(" << a << ", " << b << "), ";
    // } cout << '\n';
    // for(auto [a, b] : sb) {
    //     cout << "(" << a << ", " << b <<  "), ";
    // } cout << '\n';
    int i = 0, j = 0;

    vi ans;
    int pi = -1, pj = -1;
    while(i < n && j < m) {
        if(-sa[i].second < pi){
            ++i; continue;
        }
        if(-sb[j].second < pj) {
            ++j; continue;
        }
        if(sa[i].first == sb[j].first) {
            pi = -sa[i].second;
            pj = -sb[j].second;
            ans.push_back(sa[i].first);
            ++i; ++j;
        } 
        /*
            8 7 7
            7
        */
        // else if(sa[i].first == sb[j].first && )
        else if(sa[i] >  sb[j]) ++ i;
        else ++j;
    }

    cout << ans.size() << '\n';
    for(auto x : ans) cout << x << ' ';
    if(ans.size()) cout << '\n';





	return 0;
}