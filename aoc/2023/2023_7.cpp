#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<string, int> psi;
typedef pair<string, ll> psll;
typedef vector<psi> vpsi;
typedef vector<psll> vpsll;
typedef map<string, int> msi;
typedef map<string, ll> msll;
typedef map<char, int> mci;
typedef map<char, ll> mcll;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}
ostream &operator << (ostream& os, pii &p){
    cout << p.first << " " << p.second;

    return os;
}

pii operator* (pii a, int b) {
	return {a.first * b, a.second * b};
};
void operator*= (pii&a, int b) {
	a.first*=b;
	a.second*=b;
}
pii operator+ (pii a, int b) {
	return {a.first + b, a.second + b};
}
void operator+= (pii&a, pii b){
	a.first += b.first;
	a.second += b.second;
}


string str, word;
ll cnt = 0, a, b, x, num;
vi nums;
vector<string> vstr;

char c, _;

void solve() {
	vpsll game;
	while(cin >> word >> num) {
		game.push_back({word, num});
	}

	vector<char> cards = {'J','2','3','4','5','6','7','8','9','T','Q','K','A'};
	mci order; rep(i, 0, sz(cards)) order[cards[i]] = i;

	auto comp = [&](psll a, psll b) {
		string h[] = {a.first, b.first};

		bool gr = false;
		rep(i, 0, 5) {
			if(h[0][i] == h[1][i]) continue;
			gr = order[h[0][i]] > order[h[1][i]]; break;
		}

		rep(i, 0, 2) sort(all(h[i]));

		vvi cnt(2, vi(5, 0));
		vi jcnt(2, 0);
		rep(i, 0, 2) {
			int l = 0;
			rep(j, 0, 5) {
				if(h[i][j] == 'J') {
					++jcnt[i];
					continue;
				}
				++cnt[i][l];
				if(j < 4 && h[i][j] != h[i][j+1])++l;
			}
		}

		rep(i, 0, 2) sort(rall(cnt[i])), cnt[i][0] +=jcnt[i];

		bool result;
		if(cnt[0][0] != cnt[1][0]) result = cnt[0][0] > cnt[1][0];
		else if(cnt[0][1] != cnt[1][1]) result = cnt[0][1] > cnt[1][1];
		else result = gr;

		rep(i, 0, 2) {
			cout << h[i] << " ";
			rep(j, 0, 5) cout << cnt[i][j] << " ";
			cout << '\n';
		}
		cout << result << " | " << gr << '\n';
		return result;
	};

	sort(all(game), comp);

	ll ans = 0;
	rep(i, 0, sz(game)) {
		ans += (sz(game) - i) * game[i].second;
	}

	cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	solve();
	return 0;
}