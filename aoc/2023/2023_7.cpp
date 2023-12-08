#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<vi> vvi;

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
int cnt = 0, a, b, x, num;
vi nums;
vector<string> vstr;

char c, _;

void solve() {
	vector<pair<string, int>> game;

	while(cin >> word >> num) {
		game.push_back({word, num});
	}

	vector<char> card = {'J', '2','3','4','5','6','7','8','9', 'T', 'Q','K', 'A'};
	map<char, int> ord;
	rep(i, 0, sz(card)) ord[card[i]] = i;

	auto comp = [&](pair<string, int> a, pair<string, int> b) {
		string hand[] = {a.first, b.first};

		bool gr = false;

		rep(i, 0, 5) {
			if(hand[0][i] == hand[1][i]) continue;
			gr = ord[hand[0][i]] > ord[hand[1][i]];
			break;
		}
		rep(i,0,2) sort(all(hand[i]));

		vvi cnt(2, vi(5, 0));
		
		int jcnt[] = {0,0};

		rep(i, 0, 2) {
			int l = 0;
			rep(j, 0, 5) {
				if(hand[i][j] == 'J') {
					jcnt[i]++;
					continue;
				}
				cnt[i][l]++;
				if(j < 4 && hand[i][j] != hand[i][j+1])++l;
			}
		}

		rep(i, 0, 2){
			sort(cnt[i].rbegin(), cnt[i].rend());
			cnt[i][0] += jcnt[i];
		}


		if(cnt[0][0] != cnt[1][0]) {
			return cnt[0][0] > cnt[1][0];
		} else if(cnt[0][1] != cnt[1][1]) {
			return cnt[0][1] > cnt[1][1];
		} else return gr;
	};

	sort(all(game), comp);
	ll ans = 0;
	rep(i, 0, sz(game)) {
		ans += game[i].second * (sz(game) - i);
	}	

	cout << ans << '\n';
	return;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	solve();

	return 0;
}

// 248481129
// 247683524
// 248559379

// QQ
// T55
// KK67
//  
// 32

// 253359205
// 249601543
// 249631254