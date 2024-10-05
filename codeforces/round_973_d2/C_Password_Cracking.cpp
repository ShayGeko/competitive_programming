#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


bool check(string pat) {
    cout << "? " << pat << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans == 1;
}
int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string pat = "1";
        if(!check(pat)) pat = "0";

        bool isSuf = false;
        while(sz(pat) < n) {
            if(isSuf) {
                if(check("0" + pat)) pat = "0" + pat;
                else pat = "1" + pat;
            } else {
                if(check(pat + "0")) pat+="0";
                else if(check(pat + "1")) pat+="1";
                else isSuf = true;
            }
        }

        cout << "! " << pat << '\n';
    }

	return 0;
}