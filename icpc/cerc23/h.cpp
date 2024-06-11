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

	string s;
	getline(cin, s);
	if(s == "ENCODE") {
		map<string, vector<string>> graph;
		int k = 0;
		string root;
		while(getline(cin, s)){
			stringstream sin(s);
			string par, child;
			sin >> par;
			par = par.substr(0, sz(par) - 1);
			if(k == 0) root = par;
			++k;

			while(sin >> child) graph[par].push_back(child);

		}
		stringstream s_bitstr("");
		vector<string> names;
		function<void(string)> encode = [&](string cur){
			names.push_back(cur);
			for(auto ch : graph[cur]) {
				s_bitstr << "0";
				encode(ch);
				s_bitstr << "1";
			}
		};
		
		encode(root);
		string bitstr = s_bitstr.str();

		for(auto name: names) cout << name << '\n';
		cout << bitstr << '\n';
	} else if (s == "DECODE") {
		vector<string> names;
		string bitstr;
		while(cin >> s) {
			if(s[0] != '0' && s[0] != '1') {
				names.push_back(s);
			} else {
				bitstr = s;
				break;
			}
		}

		vector<vector<string>> graph(sz(names));
		string root = names[0];

		int i = 0, j = 0;
		function<void(int)> decode = [&](int pos) {
			string cur = names[pos];
			while(i < sz(bitstr) && bitstr[i++] == '0') {
				graph[pos].push_back(names[++j]);
				decode(j);
			}
		};

		decode(0);

		rep(i, 0, sz(graph)) {
			if(graph[i].empty()) continue;
			cout << names[i] << ": ";
			for(auto name : graph[i]) {
				cout << name << " ";
			}
			cout << '\n';
		}

	}
	return 0;
}