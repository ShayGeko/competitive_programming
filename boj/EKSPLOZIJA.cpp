#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    string s, pat;
    cin >> s >> pat;

    vector<string> proc;
    for(auto c : s) {
        if(proc.empty()) proc.push_back("");
        string& st = proc.back();
        if(st.empty() || st.back() == pat[sz(st)-1] && pat[sz(st)] == c) {
            st += c;
            if(sz(st) == sz(pat) && c == pat.back()) {
                proc.pop_back();
            }
        } else {
            string st = string()+c;
            if(st != pat) proc.push_back(string()+c);
        }
    }
    if(proc.empty()) {
        cout << "FRULA\n";
    } else {
        for(auto &st : proc) cout << st;
        cout << '\n';
    }

	return 0;
}