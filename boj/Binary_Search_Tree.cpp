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
	// cin.exceptions(cin.failbit);

    vi preOrder;
    int x;
    while(cin >> x) {
        preOrder.push_back(x);
    }
    int n = sz(preOrder);
    vector<pii> children(n, {-1, -1});
    vector<int> p(n);

    p[0] = -1;
    stack<int> s;
    s.push(0); // Root node index

    for (int i = 1; i < n; ++i) {
        x = preOrder[i];
        int parent = -1;

        while (!s.empty() && preOrder[s.top()] < x) {
            parent = s.top();
            s.pop();
        }

        if (parent != -1) {
            children[parent].second = i;
        } else {
            parent = s.top();
            children[parent].first = i;
        }
        p[i] = parent;
        s.push(i);
    }


    function<void(int)> printPostorder = [&](int v) {
        auto [l, r] = children[v];
        if(l != -1) printPostorder(l);
        if(r != -1) printPostorder(r);

        cout << preOrder[v] << '\n';
    };
    
    printPostorder(0);
	return 0;
}