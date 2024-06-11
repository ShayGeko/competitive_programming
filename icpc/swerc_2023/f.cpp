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

    int n;
    cin >> n;

    vector<string> names(n);
    vector<vi> scores(n, vi(6));
    vi p(n);

    typedef tuple<int, int, string> mtype;
    auto comp = [](mtype &a, mtype &b) {
        auto &[a1,a2,a3]=a;
        auto &[b1,b2,b3] = b;
        if(a1 == b1) return a2 > b2;
        else return a1 < b1;
    };
    priority_queue<mtype, vector<mtype>, decltype(comp)> pq(comp);
    rep(i, 0, n) {
        cin >> names[i] >> p[i];
        rep(j, 0, 6) cin >> scores[i][j];

        sort(all(scores[i]));
        int mscore = 0;
        rep(j, 1, 5) mscore += scores[i][j];
        mscore += p[i] * 10;

        pq.push({mscore, i, names[i]});
    }

    int k = 0;

    multiset<int> st;

    while(pq.size() && k < 1000) {
        auto [score, i, name] = pq.top();pq.pop();

        auto it = st.lower_bound(-score);
        auto pos = distance(st.begin(), it);
        if(pos > 2) break;
        st.insert(-score);
        ++k;
        cout << name << " " << score << '\n';
    }
	return 0;
}