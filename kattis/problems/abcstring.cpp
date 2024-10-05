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

    string s;
    cin >> s;

    vector<string> strings;

    map<char, queue<string>> mp;

    /*
        A BA CA AB AC ABC CBA 

        001 011 101 111
    */

   vector<vi> nums = {
        {6, 4, 2},
        {5, 4, 1},
        {3, 2, 1}
   };

   vi cnt(8, 0);

    int maxi = 0;
    int cur = 0;
    for(auto c : s){
        bool flag = false;

        int c1 = c - 'A';
        for(auto mask : nums[c1]) {
            if(cnt[mask]) {
                flag = true;
                int newmask = mask | (1 << c1);
                --cnt[mask];
                if(newmask != 7) ++cnt[newmask]; 
                else {
                    cur--;
                }
                break;
            }
        }
        if(!flag) {
            ++cnt[1 << c1];
            ++cur;
            maxi = max(maxi, cur);
        }
    }

    cout << maxi << '\n';


	return 0;
}