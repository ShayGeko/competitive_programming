#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


bool go_left(string &s, int i) {
    if(i < 0) return true;
    if(s[i] == '_') return go_left(s, i-1);
    if(s[i] == '.') return true;
    return false;
}
bool go_right(string &s, int i) {
    if(i == sz(s)) return true;
    if(s[i] == '_') return go_right(s, i+1);
    if(s[i] == '.') return true;
    return false;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    string s;
    while(cin >> s && s != "#") {
        double sum = 0;
        rep(i, 0, sz(s)) {
            if(s[i] == '|') sum += (go_left(s, i-1) + go_right(s, i+1)) / 2.;
            else if (s[i] == '_') continue;
            else if (s[i] == '/')  sum += go_left(s, i-1);
            else if (s[i] == '\\')  sum += go_right(s, i+1);
            else if(s[i] == '.') sum +=1;
        }

        sum = sum * 100. / sz(s);
        cout << (int) sum << '\n';
    }

	return 0;
}