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

#define DEBUG 1

char c, _;
ll compute(string &runs, int i, char last, vi& run_length, int j, int cur) {
	if(i > runs.size()) return 0;
	if(i != 0) str += last;
	// cout << "\"" << str << "\" " << i << " ";
	// for(auto x : run_length) cout << x << " ";
	
	//  cout << "| " << i << " " << j << " " << cur << '\n';
	
	// cout << '\n';
	if(i == sz(runs)) {
		// cout << "REACHED END ";
	 	if (j == run_length.size()
			|| (j == run_length.size()-1 && cur == 0)) {
				// cout << "VALID\n";
				return 1;
			}
		else {
			// cout << "BOO\n";
			return 0;
		}
	}


	ll ans = 0;
	if(runs[i] == '.') {
		// cout << "going . \n";
		if(last == '#' && cur == 0) {
			ans =  compute(runs, i+1, '.', run_length, j+1, j+1 < sz(run_length)? run_length[j+1]:-1);
		} else if(last == '.') {
			ans =  compute(runs, i+1, '.', run_length, j, cur);
		} else ans =  0;
	}
	else if(runs[i] == '#') {
		// cout << "going # \n";
		if(last == '#') {
			if(j >= sz(run_length)) ans =  0;
			if(cur > 0) {
					ans =  compute(runs, i+1, '#', run_length, j, cur-1);
			} else ans =  0;
		} else {
			if(cur > 0) {
					ans =  compute(runs, i+1, '#', run_length, j, cur - 1);
			}
			else ans = 0;
		}
	} else { // '?'
		if(last == '#') {
			if(cur == 0) { // take ? as .
				// cout << "consider ? as .\n";

				ans =  compute(runs, i+1, '.', run_length,  j+1, j+1 < sz(run_length)? run_length[j+1]:-1);
			} else if( cur > 0){
				// take ? as #
				// cout << "consider ? as #\n";
				ans =  compute(runs, i+1, '#', run_length, j, cur - 1);
			} else ans = 0;
		} else {
			// start new run
			ll newcnt = 0;
			if(j < sz(run_length)) {
				// cout << "consider ? as # | new run << " << i << " " << runs.size() << " " << "\n";
				newcnt +=  compute(runs, i+1, '#', run_length, j, run_length[j]-1);
			}
			// cout << "consider ? as .\n";
			newcnt +=  compute(runs, i+1, '.', run_length, j, cur);

			ans =  newcnt;
		}
	}
	str = str.substr(0, sz(str) - 1);
	// if(ans == 0) cout << "aborted\n";
	// cout << "back to " << str << " " << i << " ANS: " << ans << '\n';
	return ans;  
}
void p1() {
	vector<string> runs;
	vector<vi> info;
	while(getline(cin, str)) {
		ss sin(str);
		sin >> word;
		runs.push_back(word);
		info.push_back({});
		while(sin >> num) {
			info.back().push_back(num);
			sin >> _;
		}
	}

	ll ans = 0;

	rep(i, 0, sz(runs)) {
		str = "";
		auto t = compute(runs[i], 0, '.', info[i], 0, info[i][0]);
		ans += t;
	}

	cout << ans << '\n';
}
void p2() {
	vector<string> runs;
	vector<vi> info;
	while(getline(cin, str)) {
		ss sin(str);
		sin >> word;
		runs.push_back(word);
		info.push_back({});
		while(sin >> num) {
			info.back().push_back(num);
			sin >> _;
		}
	}
	
	ll ans = 0;
	rep(k,0, sz(runs)) {
		string pat = runs[k];
		vi nums = info[k];
		runs[k].reserve(5*sz(runs[k]));
		nums.reserve(5 * sz(nums));
		rep(t, 0, 4) {
			runs[k] += '?' +pat;
			for(auto x : nums) info[k].push_back(x);
		}
		

		auto crun = runs[k];
		auto rlen = info[k];

		// cout << crun << '\n';
		vector<vector<vector<vll>>> dp( sz(crun) + 3, 
			vector<vector<vll>>(sz(rlen)+2, 
				vector<vll> (200, vll(2))));
		// i, j, run, cur
		// ans is sum over dp[sz(crun)][# runs][0]
		dp[0][0][0][0] = crun[0] != '#';
		dp[0][0][1][1] = crun[0] != '.';

		rep(i, 1, sz(crun)) {
			rep(j, 0, sz(rlen)+1) {

				// try to put a . here
				if(crun[i] != '#') {
					// try putting . here
					if(crun[i-1] != '#') {
						// continue run of .
						dp[i][j][0][0] += dp[i-1][j][0][0];
					}
					if(crun[i-1] != '.') {
						// end run of #
						if(j > 0) {
							dp[i][j][0][0] += dp[i-1][j-1][rlen[j-1]][1];
						}
					}
				}
				if(crun[i] != '.' && j < sz(rlen)) {
					if(crun[i-1] != '#') {
						// start run
						dp[i][j][1][1] += dp[i-1][j][0][0];
					}
					rep(r, 1, rlen[j]) {
						// continue run of #
						if(dp[i-1][j][r][1])
							dp[i][j][r+1][1] += dp[i-1][j][r][1];
					}
				}
			}
		}


		ans += 
			dp[sz(crun)-1][sz(rlen)-1][rlen.back()][1] +
			dp[sz(crun)-1][sz(rlen)][0][0];
		// for(auto c : crun) cout << c << " ";
		// cout << '\n';
	// 	rep(l, 0, 2) {
	// 		rep(i, 0, sz(crun)) {
	// 			ll a = 0;
	// 			rep(j, 0, sz(rlen)) {
	// 				rep(r, 0, rlen[j]+1) {
	// 					a += dp[i][j][r][l];
	// 				}
	// 			}
	// 			cout << a << " ";
	// 		}
	// 		cout << '\n';
	// 	}
	// cout << "--------------------------\n";
	}
	cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

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