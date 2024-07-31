#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vector<char> pre, post, inorder;
vector<char> l, r;
void dfs(char v) {
    if(v == '.') return;
    pre.push_back(v);

    dfs(l[v-'A']);
    inorder.push_back(v);
    dfs(r[v-'A']);
    post.push_back(v);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);


    int n;
    cin >> n;
    l = vector<char>(26), r = vector<char>(26);

    rep(i, 0, n) {
        char a, b, c;
        cin >> a >> b >> c;

        l[a-'A'] = b;
        r[a-'A'] = c;
    }


    dfs('A');

    for(auto x : pre) cout << x; cout << '\n';
    for(auto x : inorder) cout << x; cout << '\n';
    for(auto x : post) cout << x; cout << '\n';

	return 0;
}