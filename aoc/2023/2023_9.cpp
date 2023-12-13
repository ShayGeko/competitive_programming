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
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef pair<string, int> psi;
typedef pair<string, ll> psll;
typedef vector<psi> vpsi;
typedef vector<psll> vpsll;
typedef map<string, int> msi;
typedef map<string, ll> msll;
typedef map<char, int> mci;
typedef map<char, ll> mcll;
typedef stringstream ss;

string str, word;
ll cnt = 0, a, b, x, num;
vi nums;
vector<string> vstr;

char c, _;

void p1() {
	vector<vll> nums;
	while(getline(cin, str)) {
		ss sin(str);
		nums.push_back({});
		while(sin >> num) nums.back().push_back(num);
	}

	ll ans = 0;
	
	rep(i, 0, sz(nums)) {
		vll cur = nums[i];
		reverse(all(cur));
		
		vector<vll> nxt;
		nxt.push_back(cur);
		int t = 0;
		while(true) {
			++t;
			vll dif;
			bool allZero = true;
			rep(i, 0, sz(nxt[t-1])-1) {
				dif.push_back(nxt[t-1][i+1]-nxt[t-1][i]);
				if(dif.back() != 0) allZero = false;
			}

			rep(i, 0, sz(dif)) {
				cout << dif[i] << " ";
			}
			cout << '\n';
			nxt.push_back(dif);
			if(allZero) {
				ll val = 0;
				while(t > 0) {
					nxt[t-1].push_back(nxt[t].back()+nxt[t-1].back());
					--t;
				}
				
				ans += nxt[0].back();
				break;
			}
		}
	}

	cout << ans << '\n';

}
void p2() {
	
}
int main() {
	// cin.tie(0)->sync_with_stdio(0);

	string part;
	getline(cin, part);

	if(part == "1") p1();
	else if(part == "2") p2();
	else {
		cout << "\033[1;31minvalid input. Make sure first line is \"1\" or \"2\" to specify part\n\033[0m\n";
		while(getline(cin, str)) {};
	}
	return 0;
}