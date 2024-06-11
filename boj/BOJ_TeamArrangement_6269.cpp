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

	
	while(true) {
		map<string, int> number;
		vector<vector<tuple<int, int, string>>> players(4);

		map<char, int> posmap = {
			{'G', 0}, {'D', 1}, {'M', 2}, {'S', 3}
		};

		map<int, char> playerPos;
		rep(i, 0, 22) {
			int num; string str; char pos;
			int years = 0;
			cin >> num;
			if(num == 0) return 0;
			cin >> str >> pos;
			
			playerPos[num] = pos;

			string rest;
			getline(cin, rest);
			stringstream ss(rest);

			int a, b;char _;
			while(ss >> a) {
				ss >> _ >> b;
				years += b - a + 1;
				// cout << str << " " << a << " |  " << _ << " | "<< b << '\n';
			}


			players[posmap[pos]].push_back({
				num, years, str
			});
		}
		char _;
		vector<int> f(4, 1);
		cin >> f[1] >> _ >> f[2] >> _ >> f[3];
	
		rep(i, 0, 4) sort(all(players[i]));

		vector<tuple<int, int, string>> team;

		tuple<int,int,string> capt = {-1, -1, ""};
		bool possible = true;
		rep(i, 0, 4) {
			if(f[i] > players[i].size()) {
				possible = false;break;
			}
			rep(j, 0, f[i]) {
				auto [x, y, z] = players[i][j];
				if( tuple<int,int,string>{y,x, z} > capt) {
					capt = {y,x, z};
				}
				team.push_back(players[i][j]);
			}
		}

		if(!possible) {
			cout << "IMPOSSIBLE TO ARRANGE\n\n";
			continue;
		}
		auto [cap_y, cap_num, cap_name] = capt;

		cout << cap_num << " " << cap_name << " " << playerPos[cap_num] << " " << '\n';

		for(auto [num, y, name] : team) {
			if(num == cap_num) continue;
			cout << num << " " << name << " " << playerPos[num] << '\n';
		}
		cout << '\n';
	}


	return 0;
}